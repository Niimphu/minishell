/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:42:23 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/25 15:15:59 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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

//does this get used?
// int	count_char(char *str, char c)
// {
// 	int	i;
// 	int	char_count;

// 	i = 0;
// 	char_count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '"' || str[i] == '\'')
// 			i += skip_quotes(str + i);
// 		if (str[i] == c)
// 			char_count++;
// 		i++;
// 	}
// 	return (char_count);
// }
