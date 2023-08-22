/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:17:49 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/22 14:44:17 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal_received;

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

int	main(int argument_count, char **arguments, char **envp)
{
	t_envp	*tools;

	g_signal_received = 0;
	tools = init_tools(envp);
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
