/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:44:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/04/26 14:45:05 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if ((unsigned char )str1[i] > (unsigned char )str2[i])
			return (1);
		if ((unsigned char )str1[i] < (unsigned char )str2[i])
			return (-1);
		i++;
	}
	return (0);
}
