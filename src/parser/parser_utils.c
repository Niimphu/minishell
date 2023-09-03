/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:31:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/03 16:18:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	contains_operator(char c)
{
	if (c == '|')
		return (1);
	if (c == '>')
		return (1);
	if (c == '<')
		return (1);
	return (0);
}

int	count_cmd(char **str)
{
	int	i;

	i = 0;
	while (str[i] && !contains_operator(str[i][0]))
		i++;
	return (i);
}

int	count_quotes(char *str, char quotes)
{
	int	i;
	int	quote_count;

	i = 0;
	quote_count = 0;
	while (str[i])
	{
		if (str[i] == quotes)
			quote_count++;
		i++;
	}
	return (quote_count);
}
