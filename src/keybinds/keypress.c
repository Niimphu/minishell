/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:45:10 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/06 14:46:07 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	clear_input(int signal_number);

void	await_signals(void)
{
	signal(SIGINT, clear_input);
	signal(SIGQUIT, SIG_IGN);
}

static void	clear_input(int signal_number)
{
	if (!signal_number)
		return ;
	g_signal_received = signal_number;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}
