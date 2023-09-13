/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:25:50 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/13 17:52:57 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	execute_builtins(char **cmd, int fd_out, t_god *god_struct)
{
	if (!cmd)
		return (1);
	if (!ft_strncmp(cmd[0], "echo", 4))
		return (echo(cmd, fd_out, god_struct));
	if (!ft_strncmp(cmd[0], "cd", 2))
		return (cd(cmd[1], god_struct));
	if (!ft_strncmp(cmd[0], "pwd", 3))
		return (pwd(fd_out, god_struct));
	if (!ft_strncmp(cmd[0], "export", 6))
		return (export(cmd, fd_out, god_struct));
	if (!ft_strncmp(cmd[0], "unset", 5))
		return (unset(cmd, god_struct));
	if (!ft_strncmp(cmd[0], "exit", 4))
		exit_minishell(god_struct);
	if (!ft_strncmp(cmd[0], "env", 3))
		return (env(fd_out, god_struct));
	return (0);
}
