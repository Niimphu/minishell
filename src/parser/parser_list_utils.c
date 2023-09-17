/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:19:21 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/17 20:19:21 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	**list_to_array(t_list *list);

void	convert_commands(t_list *parser_list)
{
	t_parser	*node;

	while (parser_list)
	{
		node = (t_parser *)parser_list->content;
		node->cmd_array = list_to_array(node->cmd_list);
		ft_lstclear(&node->cmd_list, free);
		node->cmd_list = NULL;
		node->cmd = *(node->cmd_array);
		parser_list = parser_list->next;
	}
}

static char	**list_to_array(t_list *list)
{
	int		size;
	int		i;
	char	**cmd_array;
	t_list	*temp;

	size = 0;
	temp = list;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	cmd_array = ft_calloc(sizeof(char *), size + 1);
	if (!cmd_array)
		return (NULL);
	i = 0;
	temp = list;
	while (temp)
	{
		cmd_array[i++] = ft_strdup((char *)(temp->content));
		temp = temp->next;
	}
	return (cmd_array);
}
