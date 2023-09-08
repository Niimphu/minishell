/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/03 20:31:18 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	skip_quotes(char *str);

char	*lex(char *str)
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
