/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c.....                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:07:11 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/24 00:25:45 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_string(char **string)
{
	free(*string);
	*string = NULL;
}

void	free_string_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i] != NULL)
	{
		free_string(&(*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}

int	close_fd(int fd)
{
	if (fd > 0)
		close(fd);
	return (-1);
}
