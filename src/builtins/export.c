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
	int		i;
	char	**new_env;

	i = 0;
	new_env = ft_calloc(sizeof(char *), new_split_size(god_struct->env) + 2);
	if (!new_env)
		return (NULL);
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
	int		i;
	char	*tmp;
	char	*full_cmd;

	i = 1;
	full_cmd = ft_strdup("");
	if (!cmd[i])
		return (sort_env(god_struct, new_split_size(god_struct->env), 0, 0));
	while (cmd[i])
	{
		tmp = full_cmd;
		full_cmd = ft_strjoin(tmp, cmd[i]);
		free_string(&tmp);
		i++;
	}
	if (ft_strchr(cmd[1], '='))
	{
		if (!verify_identifier("export", full_cmd))
			return (1);
		god_struct->env = new_env(god_struct, full_cmd);
		if (!god_struct->env)
			return (1);
	}
	return (free_string(&full_cmd), 0);
}
