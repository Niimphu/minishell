/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/15 19:28:38 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static char	**split_input(char *input);

char	**lex(char *input, t_god *god_struct)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			i = skip_quotes(input, i);
			if (i == FAIL)
				return (free_string(&input), NULL);
		}
		if (input[i] == ' ')
			input[i] = 26;
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			if (i > 0 && input[i] != input[i - 1])
				input = insert_sub2(input, i++);
		}
		i++;
	}
	return (expander(split_input(input), god_struct));
}

static char	**split_input(char *input)
{
	char	**split_str;

	split_str = ft_split(input, 26);
	if (!split_str)
		return (free_string(&input), NULL);
	return (free_string(&input), split_str);
}

char	*insert_sub2(char *input, int pos)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(sizeof(char), (ft_strlen(input) + 3));
	if (!str)
		return (NULL);
	while (i < pos)
	{
		str[i] = input[i];
		i++;
	}
	str[i++] = 26;
	while (input[i - 1] == input[pos])
	{
		str[i] = input[i - 1];
		i++;
	}
	str[i++] = 26;
	ft_strlcpy(&str[i], &input[i - 2], ft_strlen(&input[i - 2]) + 1);
	return (free_string(&input), str);
}

char	*insert_sub1(char *input, int pos)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(sizeof(char), (ft_strlen(input) + 2));
	if (str)
	{
		while (i <= pos)
		{
			str[i] = input[i];
			i++;
		}
		while (input[i] == input[pos])
		{
			str[i] = input[i];
			i++;
		}
		str[i++] = 26;
		ft_strlcpy(&str[i], &input[i - 1], ft_strlen(&input[i - 1]) + 1);
	}
	return (free_string(&input), str);
}
