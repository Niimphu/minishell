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

static int	is_just_n(char *str);

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

static int	is_just_n(char *str)
{
	int		i;
	char	*temp;

	i = 1;
	temp = ft_strtrim(str, " ");
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] != 'n')
			return (free_string(&temp), 0);
		i++;
	}
	return (free_string(&temp), 1);
}
