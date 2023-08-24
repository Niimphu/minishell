/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:31:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/24 18:31:39 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	check_quotes(char *str);

char	*replace_whitespaces(char *str)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	if (!check_quotes(str))
		return ("Close your quotes brav");
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			i += skip_quotes(str + i);
		if (str[i] == ' ' || str[i] == '\t')
			str[i] = 26;
		i++;
	}
	return (str);
}

int	skip_quotes(char *str)
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

int	check_token(char c)
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
static int	check_quotes(char *str)
{
	int	double_quotes;
	int	single_quotes;

	double_quotes = count_quotes(str, '"');
	single_quotes = count_quotes(str, '\'');
	if (!double_quotes && !single_quotes)
		return (1);
	if ((ft_strchr(str, '"') && double_quotes % 2 == 0)
		|| (ft_strchr(str, '\'') && single_quotes % 2 == 0))
		return (1);
	else
		return (0);
}
