/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:28:22 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/11 14:40:33 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	echo(char **cmd)
{
	int	i;
	int	new_line_flag;

	i = 1;
	new_line_flag = 0;
	if (!cmd[i])
	{
		write(1, "\n", STDOUT_FILENO);
		return (0);
	}
	if (!ft_strncmp(cmd[i], "-n", 2))
	{
		new_line_flag = 1;
		while (cmd[i] && !ft_strncmp(cmd[i], "-n", 2))
			i++;	
	}
	while (cmd[i])
		ft_putstr_fd(cmd[i++], STDOUT_FILENO);
	if (new_line_flag == 0)
		write(1, "\n", STDOUT_FILENO);
	return (0);
}
