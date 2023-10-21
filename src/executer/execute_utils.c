/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:38:42 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/21 19:18:46 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <sys/stat.h>

static char	*create_path(char *cmd, char *path);

int	pipe_up(t_list *exec_list)
{
	t_exec	*exec_node;
	int		previous_pipe_read;

	previous_pipe_read = 0;
	while (exec_list)
	{
		exec_node = (t_exec *)exec_list->content;
		if (exec_list->next && pipe(exec_node->pipe_fd) == -1)
			return (1);
		if (exec_node->fd_in == 0 && previous_pipe_read != 0)
			exec_node->fd_in = previous_pipe_read;
		else
			close_fd(previous_pipe_read);
		previous_pipe_read = exec_node->pipe_fd[READ];
		if (!exec_list->next)
			break ;
		if (exec_node->fd_out == 0)
			exec_node->fd_out = exec_node->pipe_fd[WRITE];
		else
			exec_node->pipe_fd[WRITE] = close_fd(exec_node->pipe_fd[WRITE]);
		exec_list = exec_list->next;
	}
	return (0);
}

void	find_exec(t_exec *node, char **env)
{
	char		*path_var;
	char		**env_paths;
	int			i;

	if ((!access(node->cmd, X_OK) && is_path(node->cmd))
		|| (!access(node->cmd, F_OK) && access(node->cmd, X_OK) == -1))
	{
		node->path = (ft_strdup(node->cmd));
		return ;
	}
	i = 0;
	path_var = get_env_var("PATH=", env, TRIM);
	if (!path_var)
		return ;
	env_paths = ft_split(path_var, ':');
	while (env_paths[i])
	{
		node->path = create_path(node->cmd, env_paths[i++]);
		if (access(node->path, X_OK) == 0)
			return (free_string_array(&env_paths));
		free_string(&node->path);
	}
	free_string_array(&env_paths);
}

bool	is_dir(char *cmd)
{
	struct stat	st;

	if (stat(cmd, &st) == 0 && S_ISDIR(st.st_mode))
		return (true);
	return (false);
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
