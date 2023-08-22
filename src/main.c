/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:17:49 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/16 20:50:44 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*read_user_input(void)
{
	return (readline("minishell > "));
}

void	shell_loop(t_envp *tools)
{
	t_lexer input;

	//scan for input ctrl+c, ctrl +d, ctrl + "\", directions. Up down for history,left/right for curser.
	// readline from input
	input.raw_input = read_user_input();
	lexer(&input, tools);
/* 	parser(line); */	
		//execute commands (be mindful of built-in functions)
	//free readline
	free(input.raw_input);
	//free arguments
	//grap exit status from exec
}

t_envp	*init_tools(char **envp)
{
	int		i;
	t_envp	*ptr;
	
	i = 0;
	ptr = malloc(sizeof(t_envp));
	ptr->env = malloc(sizeof(char *));
	while(envp[i])
	{
		ptr->env[i] = malloc(sizeof(char) * ft_strlen(envp[i]));
		if (!ptr->env[i])
			perror("upsi no envp!");
		ptr->env[i] = envp[i];
		i++;
	}
	ptr->lexer_struct = NULL;
	return (ptr);
}

int	main(int argc, char **argv, char **envp)
{
	t_envp	*tools;

	tools = init_tools(envp);
	if (argc > 1)
	{
		perror("This programm does not support input");
		exit(1);
	}
	argv = NULL;
	shell_loop(tools);
	//cleanup after exit of shell_loop;
	return (0);
}