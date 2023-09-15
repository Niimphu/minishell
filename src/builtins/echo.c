/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:28:22 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/15 13:46:30 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//to many lines

int	echo(char **cmd, int fd_out)
{
	int	i;
	int	new_line_flag;

	i = 1;
	new_line_flag = 0;
	while (cmd[i] && !ft_strncmp(cmd[i], "-n", ft_strlen(cmd[i])))
	{
		new_line_flag = 1;
		i++;
	}
	while (cmd[i])
	{
		/* if (ft_strchr(cmd[i], '$') && !ft_strchr(cmd[i], '\'')
			&& ft_strlen(cmd[i]) > 1)
		{
			cmd[i] = get_var(cmd[i], god_struct);
			if (!cmd[i])
				return (1);
		}
		else
			cmd[i] = ft_strtrim(cmd[i], "\"\'"); */
		ft_putstr_fd(cmd[i++], fd_out);
	}
	if (new_line_flag == 0 || !cmd[1])
		ft_putstr_fd("\n", fd_out);
	return (0);
}
