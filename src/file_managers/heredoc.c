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

int	heredoc(char *file_name, char *delimiter)
{
	int		fd;
	char	*input;

	fd = open(file_name, O_RDWR | O_CREAT, 0666);
	if (fd == -1)
	{
		perror("we need to write an error function\n");
		return (fd);
	}
	input = readline(" > ");
	while (ft_strncmp(input, delimiter, ft_strlen(delimiter) + 1))
	{
		if (ft_strncmp(input, delimiter, ft_strlen(delimiter) + 1))
			write(fd, input, ft_strlen(input));
		free_string(&input);
		input = readline("> ");
	}
	close_fd(fd);
	fd = open(file_name, O_RDWR | O_CREAT, 0666);
	return (fd);
}
