/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:17:49 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/22 17:18:56 by yiwong           ###   ########.fr       */
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
		perror("This program does accept arguments\n");
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
