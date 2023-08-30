/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:49:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/29 20:29:41 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*read_user_input();

void	await_input(t_envp *tools)
{
	t_lexer	input;

	if (!tools)
		return ;
	input.raw_input = read_user_input();
	tools->lexer_struct = &input;
	lexer(tools);
	free(input.raw_input);
}

char	*read_user_input()
{
	char *input;

	input = readline(" minishell :D > ");
	add_history(input);
	return (input);
}