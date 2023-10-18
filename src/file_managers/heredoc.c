/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:33:56 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/17 14:19:25 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	heredoc(char *file_name, char *delimiter);

void	open_heredocs(t_list *parsed_list)
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
				file_node->fd
					= heredoc(file_node->filename, file_node->delimiter);
			file_list = file_list->next;
		}
		parsed_list = parsed_list->next;
	}
}

int	heredoc(char *file_name, char *delimiter)
{
	int		fd;
	char	*input;

	input = NULL;
	fd = open(file_name, O_WRONLY | O_CREAT, 0644);
	while (fd != -1)
	{
		input = readline("> ");
		if (!input || !ft_strncmp(input, delimiter, ft_strlen(delimiter) + 1))
			break ;
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free_string(&input);
	}
	free_string(&input);
	close_fd(fd);
	fd = open(file_name, O_RDONLY, 0644);
	return (fd);
}
