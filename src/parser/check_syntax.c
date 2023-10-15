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

static bool	is_bad_operator(char *string);
static bool	bad(char *node_string, bool word_expected, int operator_count);
static bool	starts_or_ends_with_pipe(t_list *lexer_list);

//static int	pipe_error(void);
//static int	skip_quotes(const char *string, int *i);

//error code 258
//int	check_syntax(char *input_string)
//{
//	int		i;
//	char	recent;
//	bool	first;
//
//	i = 0;
//	while (input_string[i] == ' ')
//		i++;
//	if (input_string[i] == '|')
//		return (pipe_error());
//	recent = 0;
//	while (input_string[i])
//	{
//		if (input_string[i] == '\'' || input_string[i] == '"')
//		{
//			if (skip_quotes(input_string, &i) == FAIL)
//				return (FAIL);
//		}
//		if (is_operator(input_string[i]))
//
//		if (input_string[i] != ' ' && input_string[i] != '\n'
//			&& input_string[i] != '\t')
//			recent = input_string[i];
//		i++;
//	}
//}
//
//static int	pipe_error(void)
//{
//	ft_putstr_fd("minishelf: syntax error near unexpected token `|'", 2);
//	return (FAIL);
//}
//
//static int	skip_quotes(const char *string, int *i)
//{
//	char	quote;
//	int		j;
//
//	j = *i;
//	quote = string[j];
//	while (string[j] && string[j] != quote)
//		j++;
//	if (!string[j])
//	{
//		ft_putstr_fd("minishelf: unclosed quote: ", 2);
//		write(1, string + (*i), 1);
//		ft_putstr_fd("\n", 2);
//		return (FAIL);
//	}
//	*i = j;
//	return (0);
//}

char	*invalid_syntax(t_list *lexer_list)
{
	t_lexer	*node;
	int		operator_count;
	bool	word_expected;

	operator_count = 0;
	word_expected = false;
	if (starts_or_ends_with_pipe(lexer_list))
		return ("|");
	while (lexer_list)
	{
		node = (t_lexer *)lexer_list->content;
		if (get_operator_id(node->string) > 4)
			operator_count++;
		else
			operator_count = 0;
		if (bad(node->string, word_expected, operator_count))
			return (node->string);
		else if (word_expected || get_operator_id(node->string) > 5)
			word_expected = !word_expected;
		if (!lexer_list->next && word_expected)
			return (node->string);
		lexer_list = lexer_list->next;
	}
	return (NULL);
}

static bool	bad(char *node_string, bool word_expected, int operator_count)
{
	if (is_bad_operator(node_string)
		|| (word_expected && get_operator_id(node_string) > 4)
		|| (operator_count >= 2 && get_operator_id(node_string) == PIPE)
		|| operator_count >= 3)
		return (true);
	return (false);
}

static bool	is_bad_operator(char *string)
{
	if (*string != '|' && *string != '<' && *string != '>')
		return (false);
	if (get_operator_id(string) < 1)
		return (true);
	return (false);
}

static bool	starts_or_ends_with_pipe(t_list *lexer_list)
{
	if (((t_lexer *)lexer_list->content)->token == PIPE)
		return (true);
	while (lexer_list->next)
		lexer_list = lexer_list->next;
	if (((t_lexer *)lexer_list->content)->token == PIPE)
		return (true);
	return (false);
}
