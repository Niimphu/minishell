/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:01:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/06 15:15:05 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

static void	clear_child_input(int signal_number);

void	await_child_signals(void)
{
	signal(SIGINT, clear_child_input);
	signal(SIGQUIT, SIG_IGN);
}

static void	clear_child_input(int signal_number)
{
	if (!signal_number)
		return ;
	g_signal_received = signal_number;
	rl_replace_line("", 0);
}
