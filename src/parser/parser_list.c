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
			file_away(parser_node->files, lexer_node,
				(lexer_list->next->content));
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

//static t_parser	*new_parser_node(char **array);
//static t_parser	*fill_node(t_parser *node, char **array);
//static void		finish_list(t_list *parser_list);
//
//t_list	*create_parser_list(char **split_string)
//{
//	t_list		*parser_list;
//	t_parser	*new_node;
//	char		**array_start;
//
//	parser_list = NULL;
//	array_start = split_string;
//	new_node = new_parser_node(split_string);
//	parser_list = ft_lstnew(new_node);
//	split_string += (next_command(split_string));
//	while (*split_string)
//	{
//		new_node = new_parser_node(split_string);
//		if (!new_node)
//		{
//			free_string_array(&array_start);
//			return (NULL);
//		}
//		ft_lstadd_back(&parser_list, ft_lstnew(new_node));
//		finish_list(parser_list);
//		split_string += (next_command(split_string));
//	}
//	free_string_array(&array_start);
//	return (parser_list);
//}
//
//static t_parser	*new_parser_node(char **array)
//{
//	t_parser	*parser_node;
//
//	parser_node = ft_calloc(1, sizeof(t_parser));
//	if (!parser_node)
//		return (NULL);
//	parser_node->cmd = NULL;
//	parser_node->operator = 0;
//	parser_node->fd = -1;
//	parser_node->outfile = false;
//	fill_node(parser_node, array);
//	return (parser_node);
//}
//
//static t_parser	*fill_node(t_parser *node, char **array)
//{
//	int		i;
//	int		command_count;
//
//	i = 0;
//	command_count = next_operator(array);
//	node->cmd = ft_calloc(command_count + 1, sizeof(char *));
//	if (!node->cmd)
//		return (NULL);
//	while (i < command_count)
//	{
//		node->cmd[i] = ft_strdup(array[i]);
//		i++;
//	}
//	node->cmd[i] = NULL;
//	if (array[i])
//		node->operator = get_operator_id(array[i]);
//	return (node);
//}
//
//static void	finish_list(t_list *parser_list)
//{
//	t_parser	*node;
//	bool		redirect_out;
//	int			i;
//
//	i = 0;
//	redirect_out = false;
//	while (parser_list)
//	{
//		node = parser_list->content;
//		node->outfile = redirect_out;
//		redirect_out = (node->operator == OUTPUT || node->operator == APPEND);
//		node->index = i++;
//		parser_list = parser_list->next;
//	}
//}
