/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:16:24 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/17 19:31:04 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../signals/signals.h"

static int type_error(char *arg, t_god *god_struct);
static int	count_error(t_god *god_struct);

void	exit_minishell(char **cmd, t_god *god_struct)
{
	int	error;

	error = god_struct->exit_status;
	if (cmd[1] && !is_valid_int(cmd[1]))
		error = type_error(cmd[1], god_struct);
	else if (cmd[1] && cmd[2])
		error = count_error(god_struct);
	else if (cmd[1])
		error = ft_atoi(cmd[1]);
	unsilence(god_struct);
	free_god_struct(&god_struct);
	clear_history();
	exit (error);
}

static int	type_error(char *arg, t_god *god_struct)
{
	ft_putstr_fd("minishelf: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	god_struct->exit_status = 255;
	return (255);
}

static int	count_error(t_god *god_struct)
{
	ft_putstr_fd("exit: too many arguments\n", 2);
	god_struct->exit_status = 1;
	return (1);
}
