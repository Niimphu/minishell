/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kekuhne <kekuhne@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:26:44 by kekuhne           #+#    #+#             */
/*   Updated: 2022/12/27 13:52:00 by kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	i = 0;
	if ((dest != src) && (n != 0))
	{
		ptr_dest = (unsigned char *)dest;
		ptr_src = (unsigned char *)src;
		while (i < n)
			ptr_dest[i++] = *ptr_src++;
	}
	return (dest);
}
