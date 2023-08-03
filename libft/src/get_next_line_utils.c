/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:11:19 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/07/10 14:32:07 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr_gnl(char *s, int c)
{
	int		i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while ((size_t)i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (size > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	len = ft_strlen(src);
	return (len);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr != NULL)
		ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
