/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:27:32 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/14 18:16:20 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//static bool	is_bad_operator(char *string);
//static bool	bad(char *node_string, bool word_expected, int operator_count);
//static bool	starts_or_ends_with_pipe(t_list *lexer_list);

//error code 258
char	*check_syntax(char *input_string)
{
	if (starts_or_ends_with_pipe())
}

static bool	starts_or_ends_with_pipe(char *input_string)
{
	no
}



//char	*invalid_syntax(t_list *lexer_list)
//{
//	t_lexer	*node;
//	int		operator_count;
//	bool	word_expected;
//
//	operator_count = 0;
//	word_expected = false;
//	if (starts_or_ends_with_pipe(lexer_list))
//		return ("|");
//	while (lexer_list)
//	{
//		node = (t_lexer *)lexer_list->content;
//		if (get_operator_id(node->string) > 4)
//			operator_count++;
//		else
//			operator_count = 0;
//		if (bad(node->string, word_expected, operator_count))
//			return (node->string);
//		else if (word_expected || get_operator_id(node->string) > 5)
//			word_expected = !word_expected;
//		if (!lexer_list->next && word_expected)
//			return (node->string);
//		lexer_list = lexer_list->next;
//	}
//	return (NULL);
//}
//
//static bool	bad(char *node_string, bool word_expected, int operator_count)
//{
//	if (is_bad_operator(node_string)
//		|| (word_expected && get_operator_id(node_string) > 4)
//		|| (operator_count >= 2 && get_operator_id(node_string) == PIPE)
//		|| operator_count >= 3)
//		return (true);
//	return (false);
//}
//
//static bool	is_bad_operator(char *string)
//{
//	if (*string != '|' && *string != '<' && *string != '>')
//		return (false);
//	if (get_operator_id(string) < 1)
//		return (true);
//	return (false);
//}
//
//static bool	starts_or_ends_with_pipe(t_list *lexer_list)
//{
//	if (((t_lexer *)lexer_list->content)->token == PIPE)
//		return (true);
//	while (lexer_list->next)
//		lexer_list = lexer_list->next;
//	if (((t_lexer *)lexer_list->content)->token == PIPE)
//		return (true);
//	return (false);
//}
