/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:57:21 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/19 16:34:05 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	set_env_condition(char *cmd, char *env)
{
	char	*cmd_var;
	char	*env_var;

	cmd_var = NULL;
	env_var = NULL;
	if (ft_strchr(cmd, '='))
		cmd_var = ft_substr(cmd, 0, first_index_of(cmd, '='));
	else
		cmd_var = ft_strdup(cmd);
	if (!cmd_var)
		return (0);
	if (ft_strchr(env, '='))
		env_var = ft_substr(env, 0, first_index_of(env, '='));
	else
		env_var = ft_strdup(env);
	if (!env_var)
		return (0);
	if (!ft_strcmp(cmd_var, env_var) && ft_strchr(cmd, '='))
		return (free_string(&cmd_var), free_string(&env_var), 1);
	if (!ft_strcmp(cmd_var, env_var) && !ft_strchr(cmd, '=')
		&& ft_strchr(env, '='))
		return (free_string(&cmd_var), free_string(&env_var), 2);
	return (free_string(&cmd_var), free_string(&env_var), 0);
}

char	**alloc_and_assign_new_env(char **original_env, char *cmd)
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
