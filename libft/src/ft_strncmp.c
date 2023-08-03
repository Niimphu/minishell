/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:54:35 by kekuhne           #+#    #+#             */
/*   Updated: 2023/06/02 14:09:39 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *str1, const char *str2, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < size)
	{
		if ((unsigned char )str1[i] > (unsigned char )str2[i])
			return (1);
		if ((unsigned char )str1[i] < (unsigned char )str2[i])
			return (-1);
		i++;
	}
	return (0);
}
