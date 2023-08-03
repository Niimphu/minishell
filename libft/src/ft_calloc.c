/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kekuhne <kekuhne@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:20:49 by kekuhne           #+#    #+#             */
/*   Updated: 2022/12/27 13:50:45 by kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		i;

	ptr = NULL;
	i = nmemb * size;
	if (i >= 0)
	{
		ptr = malloc(i);
		if (ptr != NULL)
			ft_memset(ptr, 0, i);
	}
	return (ptr);
}
