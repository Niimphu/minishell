/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:51 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/19 18:46:58 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_parser	*create_new_node(void);
static int		save_words(t_parser *parser_node, t_list *lexer);
static t_list	*add_node_to_parser_list(t_list *parser_list,
					t_parser *parser_node);

t_list	*create_parser_list(t_list *parser_list, t_list *lexer_list)
{
	t_lexer		*lexer_node;
	t_parser	*parser_node;
	bool		new_node_time;

	new_node_time = true;
	while (lexer_list)
	{
		lexer_node = (t_lexer *)lexer_list->content;
		if (new_node_time)
			parser_node = create_new_node();
		if (!parser_node)
			return (NULL);
		save_words(parser_node, lexer_list);
		if (new_node_time)
		{
			parser_list = add_node_to_parser_list(parser_list, parser_node);
			new_node_time = false;
		}
		if (lexer_node->token == PIPE || !lexer_list->next)
			new_node_time = true;
		lexer_list = lexer_list->next;
	}
	convert_commands(parser_list);
	return (parser_list);
}

static t_list	*add_node_to_parser_list(t_list *parser_list,
											t_parser *parser_node)
{
	if (parser_list == NULL)
		parser_list = ft_lstnew(parser_node);
	else
		ft_lstadd_back(&parser_list, ft_lstnew(parser_node));
	return (parser_list);
}

static t_parser	*create_new_node(void)
{
	t_parser	*new_node;

	new_node = ft_calloc(sizeof(t_parser), 1);
	if (!new_node)
		return (NULL);
	new_node->cmd = NULL;
	new_node->cmd_list = NULL;
	new_node->files = NULL;
	new_node->builtin = false;
	return (new_node);
}

static int	save_words(t_parser *parser_node, t_list *lexer_list)
{
	t_lexer	*current;

	current = (t_lexer *)(lexer_list->content);
	if (current->token == CMD)
		parser_node->cmd_list = ft_lstnew(ft_strdup(current->string));
	else if (current->token == ARG)
		ft_lstadd_back(&parser_node->cmd_list,
			ft_lstnew(ft_strdup(current->string)));
	else if (current->token > 5)
		parser_node
			= file_away(parser_node, current, lexer_list->next->content);
	return (0);
}
