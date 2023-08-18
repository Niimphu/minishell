/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:17:49 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/03 15:58:27 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal_received;

int	main(int argument_count, char **arguments, char **envp)
{
	g_signal_received = 0;
	if (argument_count > 1)
	{
		perror("This program does accept arguments\n");
		exit(1);
	}
	(void)arguments; //to ignore "unused variable" error
	while (g_signal_received != SIGQUIT)
	{
		await_signals();
		await_input(envp);
	}
	return (0);
}
