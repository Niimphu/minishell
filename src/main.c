/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:17:49 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/07 17:39:51 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal_received;

int	main(int argument_count, char **arguments, char **envp)
{
	t_god	*god_struct;

	(void)arguments;
	if (argument_count > 1)
	{
		perror("This program does not accept arguments\n");
		exit(1);
	}
	g_signal_received = 0;
	god_struct = create_god_struct(envp);
	while (g_signal_received != SIGQUIT)
	{
		await_signals();
		await_input(god_struct);
//		ft_lstclear(&god_struct->parser_list, free_parser_node);
//		ft_lstclear(&god_struct->heredoc_names, free_file_node);
	}
	free_god_struct(&god_struct);
	clear_history();
	return (0);
}
