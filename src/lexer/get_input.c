/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:49:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/24 19:00:44 by yiwong           ###   ########.fr       */
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
	return (readline("minishell :D > "));
}
