/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:17:49 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/02 16:54:51 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal_received;

int	main(int argument_count, char **arguments, char **envp)
{
	t_envp	*god_struct;

	g_signal_received = 0;
	god_struct = create_god_struct(envp);
	if (argument_count > 1)
	{
		perror("This program does not accept arguments\n");
		exit(1);
	}
	(void)arguments;
	while (g_signal_received != SIGQUIT)
	{
		await_signals();
		await_input(god_struct);
	}
	return (0);
}
