/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:53:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/11 17:24:35 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_lexer	*new_node(char *string);
static t_lexer	*tokenize(t_lexer *node, bool block_has_command,
					bool file_expected, bool delimiter_expected);

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
	static bool	file_expected = false;
	static bool	delimiter_expected = false;

	lexer_node = ft_calloc(1, sizeof(lexer_node));
	if (!lexer_node)
		return (NULL);
	lexer_node->string = ft_strdup(string);
	lexer_node = tokenize(lexer_node, block_has_command,
			file_expected, delimiter_expected);
	if (lexer_node->token == PIPE)
		block_has_command = false;
	else if (lexer_node->token == CMD)
		block_has_command = true;
	else if (lexer_node->token == HEREDOC || lexer_node->token == DELIMITER)
		delimiter_expected = !delimiter_expected;
	else if (lexer_node->token == INPUT || lexer_node->token == OUTPUT
		|| lexer_node->token == APPEND)
		file_expected = true;
	else if (lexer_node->token == FILE)
		file_expected = false;
	return (lexer_node);
}

static t_lexer	*tokenize(t_lexer *node, bool block_has_command,
		bool file_expected, bool delimiter_expected)
{
	if (get_operator_id(node->string) > 0)
		node->token = get_operator_id(node->string);
	else if (file_expected)
		node->token = FILE;
	else if (delimiter_expected)
		node->token = DELIMITER;
	else if (!block_has_command)
		node->token = CMD;
	else
		node->token = ARG;
	return (node);
}
