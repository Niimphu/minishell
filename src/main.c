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

void	shell_loop(char **envp)
{
	t_lexer input;
	
	if (!envp)
		return ;
	check_ctrl_c();
	//scan for input ctrl+c, ctrl +d, ctrl + "\", directions. Up down for history,left/right for cursor.
	// readline from input
	input.raw_input = read_user_input();
	lexer(&input);
/* 	parser(line); */	
		//execute commands (be mindful of built-in functions)
	//free readline
	free(input.raw_input);
	//free arguments
	//grap exit status from exec
}

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		perror("This program does not support input");
		exit(1);
	}
	if (!argv)
		return (1);
	shell_loop(envp);
	//cleanup after exit of shell_loop;
	return (0);
}