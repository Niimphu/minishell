/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kekuhne <kekuhne@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:01:23 by kekuhne           #+#    #+#             */
/*   Updated: 2022/12/20 19:23:11 by kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	ptr = (char *)malloc(sizeof(char) * len);
	if (ptr != NULL)
	{
		while (*s1)
			ptr[i++] = *s1++;
		while (*s2)
			ptr[i++] = *s2++;
		ptr[i] = '\0';
	}
	return (ptr);
}
