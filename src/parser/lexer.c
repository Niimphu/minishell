/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/10 16:36:54 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	skip_quotes(char *str);

char	**lex(char *input)
{
	char	**split_str;
	int		i;

	if (!input)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			i += skip_quotes(input + i);
		if (input[i] == ' ' || input[i] == '\t')
			input[i] = 26;
		i++;
	}
	split_str = split_input(input);
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

char	**split_input(char *input)
{
	int		i;
	char	**split_str;

	input = ft_strtrim(input, " \t");
	if (!input)
		return (NULL);
	split_str = ft_split(input, ' ');
	while(split_str[i])
	{
		if (ft_strrchr(split_str[i], '"') || ft_strrchr(split_str[i], '\''))
		{
			i++;
			continue;
		}
		else if (ft_strrchr(split_str[i], '|') || ft_strrchr(split_str[i], '<')
				|| ft_strrchr(split_str[i], '>'))
		{
			split_str = insert_str(split_str, split_str[i], i);
			if (!split_str)
				return (free_string(input), NULL);
		}
		i++;
	}
	return(split_str);
}

char	get_operator(char *str)
{
	if (ft)
}

char	**insert_str(char **src, char *insert, int pos)
{
	char	c;
	char	*tmp;

	c = get_operator(src[pos]);
}