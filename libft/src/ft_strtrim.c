/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kekuhne <kekuhne@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:20:18 by kekuhne           #+#    #+#             */
/*   Updated: 2022/12/27 13:48:44 by kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	trim_pony;
	size_t	trim_mullet;
	size_t	i;
	char	*ptr;

	trim_pony = 0;
	len = 0;
	while ((s1[trim_pony] != '\0') && (check_set(set, s1[trim_pony]) == 1))
		trim_pony++;
	trim_mullet = ft_strlen(s1) - 1;
	while ((trim_mullet > trim_pony) && (check_set(set, s1[trim_mullet]) == 1))
		trim_mullet--;
	len = trim_mullet - trim_pony + 1;
	ptr = (char *)malloc(sizeof(*ptr) * (len + 1));
	if (ptr != NULL)
	{
		i = -1;
		while (++i < len)
			ptr[i] = s1[trim_pony + i];
		ptr[i] = '\0';
	}
	return (ptr);
}
