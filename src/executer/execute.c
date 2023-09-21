/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:37:12 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/20 19:37:12 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	open_heredocs(t_list *parsed_list);

int	execute(t_god *god_struct, t_list *parser_list)
{
	(void)god_struct;
	open_heredocs(parser_list);
	return (0);
}

static void	open_heredocs(t_list *parsed_list)
{
	t_parser	*node;
	t_list		*file_list;
	t_file		*file_node;

	while (parsed_list)
	{
		node = (t_parser *)parsed_list->content;
		file_list = node->files;

		while (file_list)
		{
			file_node = (t_file *)(file_list->content);
			if (file_node->operator == HEREDOC)
				heredoc(file_node->filename, file_node->delimiter);
			file_list = file_list->next;
		}
		parsed_list = parsed_list->next;
	}
}
