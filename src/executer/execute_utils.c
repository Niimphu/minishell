/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:38:42 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/29 10:29:06 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*create_path(char *cmd, char *path);

char	*find_exec(t_exec *node, char **env)
{
	char	*path;
	char	**env_paths;
	int		i;

	if (access(node->cmd, X_OK) == 0)
		return (ft_strdup(node->cmd));
	i = 0;
	env_paths = ft_split(get_env_var("PATH=", env, TRIM), ':');
	while (env_paths[i])
	{
		path = create_path(node->cmd, env_paths[i++]);
		if (access(path, X_OK) == 0)
		{
			free_string_array(&env_paths);
			return (path);
		}
		free_string(&path);
	}
	free_string_array(&env_paths);
	return (NULL);
}

static char	*create_path(char *cmd, char *path)
{
	char	*slash;
	char	*ret;
	char	*temp;

	slash = "/";
	temp = ft_strjoin(path, slash);
	if (!temp)
		return (NULL);
	ret = ft_strjoin(temp, cmd);
	if (!ret)
		return (NULL);
	free(temp);
	return (ret);
}
