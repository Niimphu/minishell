/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kekuhne <kekuhne@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:33:17 by kekuhne           #+#    #+#             */
/*   Updated: 2022/12/26 14:55:45 by kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;
	size_t			len;

	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr != NULL)
	{
		i = 0;
		while (s[i])
		{
			ptr[i] = (*f)(i, s[i]);
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
