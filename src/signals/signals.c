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

#include "signals.h"
#include <termios.h>

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
	write(STDIN_FILENO, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

//void	set_signal_error(t_god *god_struct)
//{
//	if (g_signal_received == 258)
//		god_struct->exit_status = g_signal_received;
//	else if (g_signal_received > 0)
//		god_struct->exit_status = 1;
//	g_signal_received = 0;
//}

void	silence(t_god *god_struct)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, god_struct->og_termios);
	if (isatty(STDIN_FILENO))
	{
		tcgetattr(STDIN_FILENO, &term);
		term.c_lflag = term.c_lflag & ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	}
	else if (isatty(STDOUT_FILENO))
	{
		tcgetattr(STDOUT_FILENO, &term);
		term.c_lflag = term.c_lflag & ~ECHOCTL;
		tcsetattr(STDOUT_FILENO, TCSANOW, &term);
	}
	else if (isatty(STDERR_FILENO))
	{
		tcgetattr(STDERR_FILENO, &term);
		term.c_lflag = term.c_lflag & ~ECHOCTL;
		tcsetattr(STDERR_FILENO, TCSANOW, &term);
	}
}

void	unsilence(t_god *god_struct)
{
	tcsetattr(STDIN_FILENO, TCSANOW, god_struct->og_termios);
}
