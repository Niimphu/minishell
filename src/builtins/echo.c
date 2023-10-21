/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:28:22 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/21 17:27:50 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_just_n(char *str);

int	echo(char **cmd, t_god *god_struct)
{
	int	i;
	int	new_line_flag;

	i = 1;
	new_line_flag = 0;
	if (!cmd[i] && god_struct->exit_status == 1)
		return (1);
	if (!cmd[i])
		return (ft_putstr_fd("\n", STDOUT_FILENO), 0);
	if (cmd[i] && !ft_strncmp(cmd[i], "-n", 2))
	{
		if (is_just_n(cmd[i++]))
			new_line_flag = 1;
	}
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], STDOUT_FILENO);
		if (cmd[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (new_line_flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
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
