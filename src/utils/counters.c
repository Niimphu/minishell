/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:02:36 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/15 18:41:16 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//int	get_array_size(char **array)
//{
//	int	i;
//
//	i = 0;
//	while (array[i])
//		i++;
//	return (i);
//}

int	count_operators(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] == c)
	{
		if (str[i++] != c)
			break ;
	}
	return (i);
}

int	count_char(char *str, char c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (str[i])
	{
		if (str[i] == c)
			found++;
		i++;
	}
	return (found);
}
