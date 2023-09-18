/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:53:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/17 17:28:28 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_lexer	*new_node(char *string, bool reset);
static void		tokenize(t_lexer *node, int expected_token,
					bool block_has_cmd);
static int		get_expected_token(int token, bool block_has_cmd);
static bool		update_cmd_tracker(int token, bool block_has_cmd);

t_list	*create_lexer_list(char **input_array)
{
	t_list		*lexer_list;
	int			i;

	i = 0;
	lexer_list = ft_lstnew(new_node(input_array[i], true));
	while (input_array[++i])
		ft_lstadd_back(&lexer_list,
			ft_lstnew(new_node(input_array[i], false)));
	free_string_array(&input_array);
	return (lexer_list);
}

static t_lexer	*new_node(char *string, bool reset)
{
	t_lexer		*lexer_node;
	static int	expected_token = 0;
	static bool	block_has_cmd = false;

	if (reset)
	{
		expected_token = 0;
		block_has_cmd = false;
	}
	lexer_node = ft_calloc(1, sizeof(t_lexer));
	if (!lexer_node)
		return (NULL);
	lexer_node->string = ft_strdup(string);
	tokenize(lexer_node, expected_token, block_has_cmd);
	block_has_cmd = update_cmd_tracker(lexer_node->token, block_has_cmd);
	expected_token = get_expected_token(lexer_node->token, block_has_cmd);
	return (lexer_node);
}

static void	tokenize(t_lexer *node, int expected_token, bool block_has_cmd)
{
	if (get_operator_id(node->string) > 4)
		node->token = get_operator_id(node->string);
	else if (expected_token == FILE)
		node->token = FILE;
	else if (expected_token == DELIMITER)
		node->token = DELIMITER;
	else if (block_has_cmd)
		node->token = ARG;
	else
		node->token = CMD;
}

static int	get_expected_token(int token, bool block_has_cmd)
{
	if (token == PIPE || token == DELIMITER || token == FILE)
		return (0);
	else if (token == HEREDOC)
		return (DELIMITER);
	else if (token == INPUT || token == OUTPUT || token == APPEND)
		return (FILE);
	else if (block_has_cmd)
		return (ARG);
	return (0);
}

static bool	update_cmd_tracker(int token, bool block_has_cmd)
{
	if (token == PIPE)
		return (false);
	else if (token == CMD)
		return (true);
	return (block_has_cmd);
}
