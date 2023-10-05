/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:17:49 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/05 11:34:06 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal_received = 0;

int	main(int argument_count, char **arguments, char **envp)
{
	int		ret;
	t_god	*god_struct;

	(void)arguments;
	if (argument_count > 1)
	{
		perror("This program does not accept arguments\n");
		exit(1);
	}
	god_struct = create_god_struct(envp);
	while (g_signal_received != SIGQUIT)
	{
		await_signals();
		await_input(god_struct);
	}
	ret = god_struct->exit_status;
	free_god_struct(&god_struct);
	clear_history();
	return (ret);
}
