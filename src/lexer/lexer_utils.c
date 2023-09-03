/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:31:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/03 14:21:59 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// static int	check_quotes(char *str);
static int	skip_quotes(char *str);

char	*replace_whitespaces(char *str)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	// if (!check_quotes(str))
	// 	return ("Close your quotes brav");
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			i += skip_quotes(str + i);
		if (str[i] == ' ' || str[i] == '\t')
			str[i] = 26;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] != 26)
			break ;
		i++;
	}
	if (!str[i])
		return (NULL);
	return (str);
}

static int	skip_quotes(char *str)
{
	int		i;
	char	c;

	i = 1;
	c = str[0];
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	perror("Unclosed quotes found");
	return (0);
}

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

//test failed: grep "don't" '"' ""
// static int	check_quotes(char *str)
// {
// 	int	double_quotes;
// 	int	single_quotes;

// 	double_quotes = count_quotes(str, '"');
// 	single_quotes = count_quotes(str, '\'');
// 	if (!double_quotes && !single_quotes)
// 		return (1);
// 	if (double_quotes % 2 == 0 && single_quotes % 2 == 0)
// 		return (1);
// 	else
// 		return (0);
// }
