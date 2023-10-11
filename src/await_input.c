/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   await_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:49:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/05 00:03:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*read_user_input(void);

void	await_input(t_god *god_struct)
{
	char	*input;
	int		error;

	if (!god_struct)
		return ;
	input = read_user_input();
	if (!input)
	{
		error = god_struct->exit_status;
		free_god_struct(&god_struct);
		clear_history();
		exit(error);
	}
	if (parse(input, god_struct) == -1)
		return ;
	god_struct->exit_status = execute(god_struct, god_struct->parser_list);
	ft_lstclear(&god_struct->parser_list, free_parser_node);
	ft_lstclear(&god_struct->exec_list, free_exec_node);
}

static char	*read_user_input(void)
{
	char	*input;

	input = readline("\033[0;34mminishelf > \033[0m");
	if (input && *input && *input != ' ')
		add_history(input);
	return (input);
}
