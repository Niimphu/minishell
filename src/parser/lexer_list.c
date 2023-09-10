/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:53:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/10 19:53:31 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_lexer	*new_node(char *string);

t_list	*create_lexer_list(char **input_array)
{
	t_list		*lexer_list;
	int			i;

	i = 0;
	lexer_list = ft_lstnew(new_node(input_array[i]));
	while (input_array[++i])
		ft_lstadd_back(&lexer_list,
			ft_lstnew(new_node(input_array[i])));
	free_string_array(&input_array);
	return (lexer_list);
}

static t_lexer	*new_node(char *string)
{
	t_lexer		*lexer_node;
	static bool	block_has_command = false;

	lexer_node = ft_calloc(1, sizeof(lexer_node));
	if (!lexer_node)
		return (NULL);
	lexer_node->string = ft_strdup(string);
	if (get_operator_id(string) > 0)
		lexer_node->token = get_operator_id(string);
	else if (!block_has_command)
	{
		lexer_node->token = CMD;
		block_has_command = true;
	}
	else
		lexer_node->token = ARG;
	if (lexer_node->token == PIPE)
		block_has_command = false;
	return (lexer_node);
}
