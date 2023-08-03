/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:20:17 by kekuhne           #+#    #+#             */
/*   Updated: 2023/02/19 14:59:18 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (NULL);
	while (*s != '\0')
		ptr[i++] = *s++;
	ptr[i] = '\0';
	return (ptr);
}
