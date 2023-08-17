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

char	*read_user_input(void)
{
	return (readline("minishell > "));
}

void	await_input(char **envp)
{
	t_lexer	input;

	if (!envp)
		return ;
	input.raw_input = read_user_input();
	lexer(&input);
	free(input.raw_input);
}

int	main(int argument_count, char **arguments, char **envp)
{
	global_signal_number = 0;
	if (argument_count > 1)
	{
		perror("This program does accept arguments\n");
		exit(1);
	}
	(void)arguments; //to ignore "unused variable" error
	await_signals();
	while (!global_signal_number)
		await_input(envp);
	return (0);
}
