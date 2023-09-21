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

int	heredoc(char *file_name, char *limiter)
{
	int		fd;
	char	*input;

	input = NULL;
	fd = open(file_name, O_RDWR | O_CREAT, 0666);
	while (fd != -1)
	{
		input = get_next_line(STDIN_FILENO);
		if (ft_strncmp(input, limiter, ft_strlen(input) - 1) == 0
			&& ft_strlen(input) == ft_strlen(limiter) + 1)
		{
			free_string(&input);
			break ;
		}
		write(fd, input, ft_strlen(input));
		free_string(&input);
	}
	close_fd(fd);
	fd = open(file_name, O_RDWR | O_CREAT, 0666);
	return (fd);
}
