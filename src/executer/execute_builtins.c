/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:25:50 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/14 12:30:49 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins/builtins.h"

int	execute_builtins(char **cmd, t_god *god_struct)
{
	if (!cmd)
		return (1);
	if (!ft_strncmp(cmd[0], "echo", 4))
		return (echo(cmd));
	if (!ft_strncmp(cmd[0], "cd", 2))
		return (cd(cmd[1], god_struct));
	if (!ft_strncmp(cmd[0], "pwd", 3))
		return (pwd(god_struct));
	if (!ft_strncmp(cmd[0], "export", 6))
		return (export(cmd, god_struct));
	if (!ft_strncmp(cmd[0], "unset", 5))
		return (unset(cmd, god_struct));
	if (!ft_strncmp(cmd[0], "exit", 4))
		exit_minishell(cmd, god_struct);
	if (!ft_strncmp(cmd[0], "env", 3))
		return (env(cmd, god_struct));
	return (FAIL);
}
