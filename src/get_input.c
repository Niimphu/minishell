/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:49:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/13 17:00:16 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*read_user_input(void);

void	await_input(t_god *god_struct)
{
	char	*input;

	if (!god_struct)
		return ;
	input = read_user_input();
	if (input)
		parse(input, god_struct);
	else
		exit_minishell(god_struct);
	execute(god_struct, god_struct->parser_list);
	ft_lstclear(&god_struct->parser_list, free_parser_node);
}

static char	*read_user_input(void)
{
	char	*input;

	input = readline("minishelf > ");
	add_history(input);
	return (input);
}