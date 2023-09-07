/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:51 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/06 22:57:02 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_parser	*new_parser_node(char **array);
static t_parser	*fill_node(t_parser *node, char **array);
static int		get_operator_id(char *operator_string);

t_list	*create_parser_list(char **split_string)
{
	t_list		*parser_list;
	t_parser	*new_node;
	char		**array_start;

	array_start = split_string;
	new_node = new_parser_node(split_string);
	parser_list = ft_lstnew(new_node);
	split_string += (next_command(split_string));
	while (*split_string)
	{
		new_node = new_parser_node(split_string);
		ft_lstadd_back(&parser_list, ft_lstnew(new_node));
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

static int	get_operator_id(char *operator_string)
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
