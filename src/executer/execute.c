/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:37:12 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/24 00:38:40 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fork_this(t_god *god_struct, t_exec *exec_node,
				bool first, bool last);

int	execute(t_god *god_struct, t_list *parser_list)
{
	t_exec		*exec_node;
	int			i;

	i = 0;
	open_heredocs(parser_list);
	open_files(parser_list);
	god_struct->exec_list = create_execution_list(parser_list);
	while (++i <= god_struct->block_count)
	{
		exec_node = god_struct->exec_list->content;
		fork_this(god_struct, exec_node,
			i == 0, i == god_struct->block_count);
		parser_list = parser_list->next;
	}
	return (0);
}

static int	fork_this(t_god *god_struct, t_exec *exec_node,
				bool first, bool last)
{
	(void)god_struct;
	(void)exec_node;
	(void)first;
	(void)last;
	return (0);
}
