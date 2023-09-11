/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:49:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/08 15:51:35 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*read_user_input(void);

void	await_input(t_god *god_struct)
{
	char	*input;

	if (!god_struct)
		return ;
	input = read_user_input();
	if (!input)
		exit(0);
	if (parse(input, god_struct) == -1)
	{
		free_string(&input);
		return ;
	}
	if (!is_syntax_valid(god_struct->parser_list))
		write(2, "syntax error: unexpected token\n", 35);
	free_string(&input);
}

static char	*read_user_input(void)
{
	char	*input;

	input = readline("minishelf > ");
	add_history(input);
	return (input);
}
