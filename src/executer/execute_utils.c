/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:38:42 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/03 15:01:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*create_path(char *cmd, char *path);

int	pipe_up(t_list *exec_list)
{
	t_exec	*exec_node;
	int		previous_pipe_read;

	previous_pipe_read = -1;
	while (exec_list)
	{
		exec_node = (t_exec *)exec_list->content;
		if (exec_list->next && pipe(exec_node->pipe_fd) == -1)
			return (1);
		if (exec_node->fd_in == -1 && previous_pipe_read != -1)
			exec_node->fd_in = previous_pipe_read;
		else
			previous_pipe_read = close_fd(previous_pipe_read);
		previous_pipe_read = exec_node->pipe_fd[READ];
		if (!exec_list->next)
			break ;
		if (exec_node->fd_out == -1)
			exec_node->fd_out = exec_node->pipe_fd[WRITE];
		else
			exec_node->pipe_fd[WRITE] = close_fd(exec_node->pipe_fd[WRITE]);
		exec_list = exec_list->next;
	}
	return (0);
}

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
	free_string(&temp);
	if (!ret)
		return (NULL);
	return (ret);
}

int	close_all_pipes(t_list *exec_list)
{
	t_exec	*exec_node;

	while (exec_list)
	{
		exec_node = (t_exec *)exec_list->content;
		exec_node->pipe_fd[READ] = close_fd(exec_node->pipe_fd[READ]);
		exec_node->pipe_fd[WRITE] = close_fd(exec_node->pipe_fd[WRITE]);
		exec_list = exec_list->next;
	}
	return (0);
}
