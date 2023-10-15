/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:31:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/14 18:13:39 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*remove_quotes(char *string);
static bool	do_it(const char *string, int i, char quote);

int	get_operator_id(char *operator_string)
{
	if (!ft_strncmp("|", operator_string, 2))
		return (PIPE);
	if (!ft_strncmp("<", operator_string, 2))
		return (INPUT);
	if (!ft_strncmp(">", operator_string, 2))
		return (OUTPUT);
	if (!ft_strncmp("<<", operator_string, 3))
		return (HEREDOC);
	if (!ft_strncmp(">>", operator_string, 3))
		return (APPEND);
	else
		return (BAD_OPERATOR);
}

void	trim_quotes(t_list *lexer_list)
{
	t_lexer	*node;
	char	*trimmed;

	while (lexer_list)
	{
		node = (t_lexer *)lexer_list->content;
		if (ft_strchr(node->string, '\'') && ft_strchr(node->string, '"'))
		{
			trimmed = remove_quotes(node->string);
			free_string(&node->string);
			node->string = trimmed;
		}
		lexer_list = lexer_list->next;
	}
}

static char	*remove_quotes(char *string)
{
	int		i;
	int		j;
	char	*trimmed;
	char	quote;

	trimmed = ft_calloc(ft_strlen(string), sizeof(char));
	if (!trimmed)
		return (NULL);
	i = 0;
	j = 0;
	quote = 0;
	while (string[i])
	{
		if (do_it(string, i, quote))
		{
			if (quote == 0)
				quote = string[i];
			else if (string[i] == quote)
				quote = 0;
			i++;
		}
		else
			trimmed[j++] = string[i++];
	}
	return (trimmed);
}

static bool	do_it(const char *string, int i, char quote)
{
	return ((string[i] == '\'' || string[i] == '"')
		&& (string[i] == quote || quote == 0));
}
