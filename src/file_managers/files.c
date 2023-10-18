/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:08:01 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/03 16:49:06 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

static int	open_file(char *filename, int operator);
static int	error(char *filename);

int	open_files(t_list *parsed_list, t_god *god_struct)
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
			if (file_node->fd == -1)
			{
				error(file_node->filename);
				file_list = ft_lstlast(file_list);
				god_struct->exit_status = 1;
			}
			file_list = file_list->next;
		}
		parsed_list = parsed_list->next;
	}
	return (0);
}

static int	open_file(char *filename, int operator)
{
	int	fd;

	if (operator == OUTPUT)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
				| S_IRGRP | S_IWGRP | S_IROTH);
	if (operator == APPEND)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR
				| S_IRGRP | S_IWGRP | S_IROTH);
	if (operator == INPUT)
		fd = open(filename, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
	return (fd);
}

static int	error(char *filename)
{
	ft_putstr_fd("minishelf: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (FAIL);
}
