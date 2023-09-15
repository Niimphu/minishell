/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:51 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/14 18:13:39 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//t_list	*create_parser_list(t_list *lexer_list)
//{
//	t_list		*parser_list;
//	t_parser	*new_node;
//
//	if (!check_syntax())
//}


static t_parser	*new_parser_node(char **array);
static t_parser	*fill_node(t_parser *node, char **array);
static void		finish_list(t_list *parser_list);

t_list	*create_parser_list(char **split_string)
{
	t_list		*parser_list;
	t_parser	*new_node;
	char		**array_start;

	parser_list = NULL;
	array_start = split_string;
	new_node = new_parser_node(split_string);
	parser_list = ft_lstnew(new_node);
	split_string += (next_command(split_string));
	while (*split_string)
	{
		new_node = new_parser_node(split_string);
		if (!new_node)
		{
			free_string_array(&array_start);
			return (NULL);
		}
		ft_lstadd_back(&parser_list, ft_lstnew(new_node));
		finish_list(parser_list);
		split_string += (next_command(split_string));
	}
	free_string_array(&array_start);
	return (parser_list);
}

static t_parser	*new_parser_node(char **array)
{
	t_parser	*parser_node;

	parser_node = ft_calloc(1, sizeof(t_parser));
	if (!parser_node)
		return (NULL);
	parser_node->cmd = NULL;
	parser_node->operator = 0;
	parser_node->fd = -1;
	parser_node->outfile = false;
	fill_node(parser_node, array);
	return (parser_node);
}

static t_parser	*fill_node(t_parser *node, char **array)
{
	int		i;
	int		command_count;

	i = 0;
	command_count = next_operator(array);
	node->cmd = ft_calloc(command_count + 1, sizeof(char *));
	if (!node->cmd)
		return (NULL);
	while (i < command_count)
	{
		node->cmd[i] = ft_strdup(array[i]);
		i++;
	}
	node->cmd[i] = NULL;
	if (array[i])
		node->operator = get_operator_id(array[i]);
	return (node);
}

static void	finish_list(t_list *parser_list)
{
	t_parser	*node;
	bool		redirect_out;
	int			i;

	i = 0;
	redirect_out = false;
	while (parser_list)
	{
		node = parser_list->content;
		node->outfile = redirect_out;
		redirect_out = (node->operator == OUTPUT || node->operator == APPEND);
		node->index = i++;
		parser_list = parser_list->next;
	}
}
