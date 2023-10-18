/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:01:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/18 19:39:05 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

static void	clear_child_input(int signal_number);
static void	quit(int signal_number);

void	await_child_signals(void)
{
	signal(SIGINT, clear_child_input);
	signal(SIGQUIT, quit);
}

static void	clear_child_input(int signal_number)
{
	if (!signal_number)
		return ;
	g_signal_received = signal_number;
	rl_replace_line("", 0);
}

static void	quit(int signal_number)
{
	if (!signal_number)
		return ;
	g_signal_received = signal_number;
	ft_putstr_fd("Quit 3\n", 2);
	rl_replace_line("", 0);
}
