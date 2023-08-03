/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:56:26 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/04/18 14:24:41 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr_node;
	t_list	*next_node;

	curr_node = *lst;
	while (curr_node->next)
	{
		next_node = curr_node->next;
		del(curr_node->content);
		free(curr_node);
		curr_node = next_node;
	}
	*lst = NULL;
}
