/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:33:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/23 18:33:52 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static t_exec	*new_node(t_parser *parser_node);

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
	exec_node->cmd = exec_node->cmd_array[0];
	exec_node->fd_in = -1;
	exec_node->fd_out = -1;
	exec_node->pipe_fd[0] = -1;
	exec_node->pipe_fd[1] = -1;
	return (exec_node);
}
