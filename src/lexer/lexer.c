/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/25 15:14:21 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	print_lexer_list(t_lexer *lexed_list);

void	lexer(char *input, t_envp *god_struct)
{
	t_lexer	*lexed_list;
	char	**split_str;

	input = replace_whitespaces(input);
	printf("input line: %s\n===============\n", input);
	if (!input)
		quit(0);
	if (!ft_strncmp(input, "", 1))
		return ;
	split_str = ft_split(input, 26);
	if (!ft_strncmp(split_str[0], "exit", 4))
		quit(0);
	lexed_list = lexer_list_init(split_str);
	god_struct->lexer_list = lexed_list;
	expander(&lexed_list, god_struct);
	print_lexer_list(god_struct->lexer_list);
	god_struct->lexer_list = NULL;
}

static void	print_lexer_list(t_lexer *lexed_list)
{
	int	i;
	int	j;

	printf("\n=== Lexer linked list ===\n");
	j = 0;
	while (lexed_list)
	{
		i = 0;
		while (lexed_list->cmd[i])
		{
			printf("cmd[%d] of node %d is : %s\n", i, j, lexed_list->cmd[i]);
			i++;
		}
		printf("command line operator of node %d is : %s\n", j, lexed_list->operator);
		j++;
		lexed_list = lexed_list->next;
	}
	printf("===    End of list    ===\n\n");
}
