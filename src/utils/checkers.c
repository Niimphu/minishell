/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:38:06 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/05 00:14:38 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	is_valid_int(char *string)
{
	int	i;

	i = 0;
	while (string[i] == '+' || string[i] == '-')
		i++;
	if (ft_isdigit(string + i))
		return (true);
	return (false);
}

bool	is_path(char *string)
{
	return (*string == '/' || !ft_strncmp(string, "./", 2));
}
