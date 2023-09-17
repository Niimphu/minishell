/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:51 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/15 20:04:58 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_parser	*create_new_node(void);

t_list	*create_parser_list(t_god *god_struct, t_list *lexer_list)
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
		if (lexer_node->token > 5)
		{
			file_away(parser_node->files, lexer_node,
				(lexer_list->next->content));
			lexer_list = lexer_list->next;
		}
		else if (lexer_node->token == CMD)
			parser_node->cmd_list = ft_lstnew(ft_strdup(lexer_node->string));
		else if (lexer_node->token == ARG)
			ft_lstadd_back(&parser_node->cmd_list,
				ft_lstnew(ft_strdup(lexer_node->string)));
		if (new_node_time)
		{
			if (god_struct->parser_list == NULL)
				god_struct->parser_list = ft_lstnew(parser_node);
			else
				ft_lstadd_back(&god_struct->parser_list,
					ft_lstnew(parser_node));
			new_node_time = false;
		}
		if (lexer_node->token == PIPE)
			new_node_time = true;
		lexer_list = lexer_list->next;
	}
	return (god_struct->parser_list);
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
