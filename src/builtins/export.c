/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:32:33 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/03 16:23:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "builtins.h"

static int	sort_env(t_god *god_struct, int size, int i, int j);
static void	print_sorted_env(char **env);
static char	**alloc_and_assign_new_env(char **original_env, char *cmd);

int	export(char **cmd, t_god *god_struct)
{
	int	i;

	i = 1;
	if (!cmd[i])
		return (sort_env(god_struct, new_split_size(god_struct->env), 0, 0));
	while (cmd[i])
	{
		if (!verify_identifier("export", cmd[i]))
			return (1);
		god_struct->env = new_env(god_struct, cmd[i]);
		if (!god_struct->env)
			return (1);
		i++;
	}
	return (0);
}

static int	sort_env(t_god *god_struct, int size, int i, int j)
{
	char	*temp;
	char	**env_array;

	env_array = cpy_env(god_struct->env, size);
	if (!env_array)
		return (1);
	while (i < size)
	{
		j = 0;
		while (env_array[j + 1] && j < size - i)
		{
			temp = NULL;
			if (ft_strcmp(env_array[j], env_array[j + 1]) > 0)
			{
				temp = env_array[j];
				env_array[j] = env_array[j + 1];
				env_array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	print_sorted_env(env_array);
	return (free_string_array(&env_array), 0);
}

char	**new_env(t_god *god_struct, char *cmd)
{
	int		i;
	bool	found;

	i = 0;
	found = false;
	while (god_struct->env[i])
	{
		if (set_env_condition(cmd, god_struct->env[i]) == 1)
		{
			free_string(&god_struct->env[i]);
			god_struct->env[i] = ft_strdup(cmd);
			found = true;
		}
		if (set_env_condition(cmd, god_struct->env[i]) == 2)
			found = true;
		i++;
	}
	if (!found)
		god_struct->env = alloc_and_assign_new_env(god_struct->env, cmd);
	return (god_struct->env);
}

static char	**alloc_and_assign_new_env(char **original_env, char *cmd)
{
	char	**env;
	int		i;

	env = ft_calloc(new_split_size(original_env) + 2, sizeof(char *));
	if (!env)
		return (NULL);
	i = 0;
	while (original_env[i])
	{
		env[i] = ft_strdup(original_env[i]);
		if (!env[i])
			perror("rip");
		i++;
	}
	env[i++] = ft_strdup(cmd);
	env[i] = NULL;
	free_string_array(&original_env);
	return (env);
}

static void	print_sorted_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strcmp(env[i], "###"))
			i++;
		else
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(env[i], STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
			i++;
		}
	}
}
