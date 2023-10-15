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

static void	print_sorted_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd(env[i], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
}

static int	sort_env(t_god *god_struct, int size, int i, int j)
{
	char	*tmp;
	char	**env_array;

	env_array = cpy_env(god_struct->env, size);
	if (!env_array)
		return (1);
	while (i < size)
	{
		j = 0;
		while (env_array[j + 1] && j < size - i)
		{
			tmp = NULL;
			if (ft_strcmp(env_array[j], env_array[j + 1]) > 0)
			{
				tmp = env_array[j];
				env_array[j] = env_array[j + 1];
				env_array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	print_sorted_env(env_array);
	return (free_string_array(&env_array), 0);
}

static char	**new_env(t_god *god_struct, char *cmd)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (god_struct->env[i])
	{
		if (!ft_strncmp(cmd, god_struct->env[i], first_index_of(god_struct->env[i], '='))
			&& !ft_strncmp(cmd, god_struct->env[i], ft_strlen(cmd)))
		{
			printf("%c\n", god_struct->env[i][first_index_of(god_struct->env[i], '=')]);
			free_string(&god_struct->env[i]);
			god_struct->env[i] = ft_strdup(cmd);
			found = 1;
		}
		i++;
	}
	if (found == 0)
	{
		god_struct->env = realloc(god_struct->env, sizeof(char *) * (new_split_size(god_struct->env) + 2));
		god_struct->env[i++] = ft_strdup(cmd);
		god_struct->env[i] = NULL;

	}
	return (god_struct->env);
}

int	export(char **cmd, t_god *god_struct)
{
	int		i;

	i = 1;
	if (!cmd[i])
		return (sort_env(god_struct, new_split_size(god_struct->env), 0, 0));
	if (!verify_identifier("export", cmd[i]))
		return (2);
	if (ft_strchr(cmd[i], '='))
	{
		god_struct->env = new_env(god_struct,cmd[i]);
		if (!god_struct->env)
			return (1);
	}
	return (0);
}
