/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kekuhne <kekuhne@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:47:08 by kekuhne           #+#    #+#             */
/*   Updated: 2022/12/27 13:48:30 by kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*set_array(char *ptr, int n, int sign, size_t array_len)
{
	if (n < 0)
	{
		ptr[0] = '-';
		n = n * sign;
	}
	ptr[array_len] = '\0';
	array_len--;
	while (n > 0)
	{
		ptr[array_len] = n % 10 + '0';
		n = n / 10;
		array_len--;
	}
	return (ptr);
}

static size_t	get_size(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	int				sign;
	size_t			array_len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	array_len = get_size(n);
	ptr = (char *)malloc(sizeof(char) * array_len + 1);
	if (ptr == NULL)
		return (NULL);
	set_array(ptr, n, sign, array_len);
	return (ptr);
}
