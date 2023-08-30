/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:38:06 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/26 18:39:59 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ends_with_operator(char **array)
{
	int	i;

	i = 0;
	while (array[i + 1])
		i++;
	return (contains_operator(*array[i]));
}
