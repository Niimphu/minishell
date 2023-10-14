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

static void	sort_env(t_god *god_struct, int size, int i, int j)
{
	char	*tmp;
	char	**env_array;

	env_array = cpy_env(god_struct->env, size);
	if (!env_array)
		return ;
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
	free_string_array(&env_array);
}

static char	**new_env(t_god *god_struct, char *cmd)
{
	int		i;
	char	**new_env;

	i = 0;
	while (god_struct->env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (NULL);
	i = 0;
	while (god_struct->env[i])
	{
		new_env[i] = ft_strdup(god_struct->env[i]);
		if (!new_env[i])
			return (NULL);
		i++;
	}
	new_env[i] = ft_strdup(cmd);
	if (!new_env[i])
		return (NULL);
	new_env[++i] = NULL;
	return (free_string_array(&god_struct->env), new_env);
}

int	export(char **cmd, t_god *god_struct)
{
	if (!cmd[1])
	{
		sort_env(god_struct, new_split_size(god_struct->env), 0, 0);
		return (0);
	}
	if (!verify_identifier("export", cmd[1]))
		return (1);
	if (ft_strchr(cmd[1], '='))
	{
		god_struct->env = new_env(god_struct, cmd[1]);
		if (!god_struct->env)
			return (1);
	}
	return (0);
}
