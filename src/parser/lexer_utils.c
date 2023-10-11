/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:48:27 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/04 18:10:14 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	first_index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	next_is_operator(char **split_str, int index)
{
	int	next_index;

	next_index = index + 1;

	if (!split_str[next_index])
		return (0);
	if (split_str[next_index][0] == '|' || split_str[next_index][0] == '<'
		|| split_str[next_index][0] == '>')
		return (1);
	else
		return (0);
}

bool	set_trim(char **split_string, int i, bool trim)
{
	if (trim == true || next_is_operator(split_string, i))
		return (false);
	else
		return (true);
}

//int	skip_quotes(const char *str)
//{
//	int		i;
//	char	c;
//
//	i = 1;
//	c = str[0];
//	while (str[i])
//	{
//		if (str[i] == c)
//			return (i);
//		else
//			i++;
//	}
//	write(2, "Unclosed quotes found: ", 23);
//	write(2, &c, 1);
//	write(2, "\n", 1);
//	return (-1);
//}
//
//int	second_index_of(char *str, char c)
//{
//	int	i;
//	int	found;
//
//	i = 0;
//	found = 0;
//	while (str[i])
//	{
//		if (str[i] == c)
//			found++;
//		if (found == 2)
//			return (i);
//		i++;
//	}
//	return (-1);
//}
