/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:27:32 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/06 23:44:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	ends_with_operator(t_list *parsed_list);
static bool	is_node_valid(t_parser *node);

bool	is_syntax_valid(t_list *parsed_list)
{
	if (!parsed_list)
		return (true);
	if (ends_with_operator(parsed_list))
		return (false);
	while (parsed_list)
	{
		if (!is_node_valid(parsed_list->content))
			return (false);
		parsed_list = parsed_list->next;
	}
	return (true);
}

static bool	ends_with_operator(t_list *parsed_list)
{
	while (parsed_list->next)
		parsed_list = parsed_list->next;
	if (((t_parser *)parsed_list->content)->operator)
		return (true);
	return (false);
}

static bool	is_node_valid(t_parser *node)
{
	if (node->operator == BAD_OPERATOR || !*node->cmd)
		return (false);
	return (true);
}
