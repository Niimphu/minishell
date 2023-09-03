/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:49:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/02 20:28:34 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*read_user_input(void);

void	await_input(t_envp *god_struct)
{
	char	*input;

	if (!god_struct)
		return ;
	input = read_user_input();
	lexer(input, god_struct);
}

static char	*read_user_input(void)
{
	char *input;

	input = readline(" minishell :D > ");
	add_history(input);
	return (input);
}
