/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:28:22 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/17 19:05:05 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_just_n(char *str)
{
	int	i;
	char *tmp;

	i = 1;
	tmp = ft_strtrim(str, " ");
	if (!tmp)
		return (0);
	while (tmp[i])
	{
		if (tmp[i] != 'n')
			return (free_string(&tmp), 0);
		i++;
	}
	return (free_string(&tmp), 1);
}

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
	while (cmd[i] && !ft_strncmp(cmd[i], "-n", 2))
	{
		if (!is_just_n(cmd[i]))
			break ;
		new_line_flag = 1;
		i++;
	}
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], STDOUT_FILENO);
		if (cmd[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (new_line_flag == 0)
		write(1, "\n", STDOUT_FILENO);
	return (0);
}
