/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:33:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/01 18:07:50 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static t_exec	*new_node(t_parser *parser_node);
static t_exec	*get_redirection_fds(t_exec *exec_node, t_list *files);

t_list	*create_execution_list(t_list *parser_list)
{
	t_list		*exec_list;
	t_parser	*parser_node;

	exec_list = NULL;
	while (parser_list)
	{
		parser_node = parser_list->content;
		if (!exec_list)
			exec_list = ft_lstnew(new_node(parser_node));
		else
			ft_lstadd_back(&exec_list, ft_lstnew(new_node(parser_node)));
		parser_list = parser_list->next;
	}
	return (exec_list);
}

static t_exec	*new_node(t_parser *parser_node)
{
	t_exec	*exec_node;

	exec_node = ft_calloc(1, sizeof(t_exec));
	if (!exec_node)
		return (NULL);
	exec_node->cmd_array = parser_node->cmd_array;
	while (exec_node->cmd_array[0] && !ft_strlen(exec_node->cmd_array[0]))
		exec_node->cmd_array++;
	exec_node->cmd = exec_node->cmd_array[0];
	exec_node->builtin = parser_node->builtin;
	exec_node->fd_in = 0;
	exec_node->fd_out = 0;
	exec_node->pipe_fd[0] = 0;
	exec_node->pipe_fd[1] = 0;
	exec_node->path = NULL;
	get_redirection_fds(exec_node, parser_node->files);
	return (exec_node);
}

static t_exec	*get_redirection_fds(t_exec *exec_node, t_list *files)
{
	t_file	*file_node;

	while (files)
	{
		file_node = (t_file *)files->content;
		if (file_node->operator == INPUT || file_node->operator == HEREDOC)
		{
			close_fd(exec_node->fd_in);
			exec_node->fd_in = file_node->fd;
		}
		if (file_node->operator == OUTPUT || file_node->operator == APPEND)
		{
			close_fd(exec_node->fd_out);
			exec_node->fd_out = file_node->fd;
		}
		files = files->next;
	}
	return (exec_node);
}
