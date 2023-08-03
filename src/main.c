/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:17:49 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/03 15:51:52 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *replace_whitespaces(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '"' || str[i] == '\'')
		{
			i++;
			while(str[i] != '"'|| str[i] == '\'')
			{
				if (!str[i])
					return (NULL);
				i++;
			}
		}
		if (str[i] == ' ')
				str[i] = 26;
		i++;
	}
	return (str);
}

char	*read_user_input(void)
{
	return (readline("minishell > "));
}


void	lexer(t_lexer *input)
{
	input->raw_input = replace_whitespaces(input->raw_input);
	printf("%s\n", input->raw_input);
}

void	shell_loop(char **envp)
{
	t_lexer input;
	
	envp = NULL;
	//scan for input ctrl+c, ctrl +d, ctrl + "\", directions. Up down for history,left/right for curser.
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
		perror("This programm does not support input");
		exit(1);
	}
	argv = NULL;
	shell_loop(envp);
	//cleanup after exit of shell_loop;
	return (0);
}