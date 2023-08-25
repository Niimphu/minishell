/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:56:26 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/25 14:54:19 by yiwong           ###   ########.fr       */
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
	lst = NULL;
}
