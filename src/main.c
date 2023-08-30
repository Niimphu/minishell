/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:17:49 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/30 15:50:22 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal_received;

int	main(int argument_count, char **arguments, char **envp)
{
	t_envp	*tools;

	g_signal_received = 0;
	tools = create_god_struct(envp);
	if (argument_count > 1)
	{
		perror("This program does not accept arguments\n");
		exit(1);
	}
	(void)arguments; //to ignore "unused variable" error
	while (g_signal_received != SIGQUIT)
	{
		await_signals();
		await_input(tools);
	}
	return (0);
}
