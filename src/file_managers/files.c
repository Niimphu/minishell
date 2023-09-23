/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:08:01 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/24 00:08:01 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

static int	open_file(char *filename, int operator);

void	open_files(t_list *parsed_list)
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
			if (file_node->operator != HEREDOC)
				file_node->fd
					= open_file(file_node->filename, file_node->operator);
			file_list = file_list->next;
		}
		parsed_list = parsed_list->next;
	}
}

static int	open_file(char *filename, int operator)
{
	int	fd;

	if (operator == OUTPUT)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0222);
	if (operator == APPEND)
		fd = open(filename, O_WRONLY | O_CREAT, 0222);
	if (operator == INPUT)
		fd = open(filename, O_RDONLY | O_CREAT | O_TRUNC, 0444);
	if (fd == -1)
		printf("open error: %s", filename);
	return (fd);
}
