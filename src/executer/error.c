/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:24:14 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/03 15:33:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	command_not_found(char *cmd)
{
	write(2, "minishelf: ", 11);
	write(2, cmd, ft_strlen(cmd));
	if (*cmd == '/' && access(cmd, X_OK) == 0)
		write (2, ": is a directory\n", 17);
	else if (*cmd == '/')
		write (2, ": no such file or directory\n", 28);
	else
		write(2, ": command not found\n", 20);
}
