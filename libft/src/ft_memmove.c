/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kekuhne <kekuhne@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:32:47 by kekuhne           #+#    #+#             */
/*   Updated: 2022/12/27 13:52:12 by kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr_dest;
	char	*ptr_src;

	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	if (dest == src)
		return (dest);
	if (ptr_src < ptr_dest)
	{
		while (n--)
			ptr_dest[n] = ptr_src[n];
		return (dest);
	}
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}
