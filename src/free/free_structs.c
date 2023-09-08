/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:41:11 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/08 14:59:20 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_parser_list(t_list *parsed_list)
{
	t_list		*current;
	t_parser	*node;
	int			i;

	i = 0;
	while (parsed_list)
	{
		node = (t_parser *)parsed_list->content;
		current = parsed_list;
		free_string_array(&node->cmd);
		if (node->operator)
			free_string(&node->operator);
		free(parsed_list->content);
		parsed_list = parsed_list->next;
		free(current);
		current = NULL;
	}
}

void	free_god_struct(t_god **god_struct)
{
	t_god	*ptr;

	ptr = *(god_struct);
	free_string_array(&ptr->env);
	free_parser_list(ptr->parser_list);
	free(ptr);
	*god_struct = NULL;
}