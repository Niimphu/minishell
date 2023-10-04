/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:16:24 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/05 00:14:56 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	type_error(char *arg);
static void	count_error(void);

void	exit_minishell(char **cmd, t_god *god_struct)
{
	int	error;

	error = god_struct->exit_status;
	if (cmd[1] && !is_valid_int(cmd[1]))
		return (type_error(cmd[1]));
	if (cmd[1] && cmd[2])
		return (count_error());
	if (cmd[1])
		error = ft_atoi(cmd[1]);
	free_god_struct(&god_struct);
	clear_history();
	exit (error);
}

static void	type_error(char *arg)
{
	ft_putstr_fd("minishelf: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

static void	count_error(void)
{
	ft_putstr_fd("exit: too many arguments\n", 2);
}
