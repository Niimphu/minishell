/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:49:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/18 14:49:16 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*read_user_input(void);

void	await_input(char **envp)
{
	t_lexer	input;

	if (!envp)
		return ;
	input.raw_input = read_user_input();
	lexer(&input);
	free(input.raw_input);
}

char	*read_user_input(void)
{
	return (readline("minishell :D > "));
}