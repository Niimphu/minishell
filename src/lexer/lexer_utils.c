/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:31:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/02 17:29:31 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	skip_quotes(char *str);

char	*replace_whitespaces(char *str)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
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
