/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/02 18:15:44 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**split_input(char *input, t_god *god_struct);
char		*insert_sub_quote(char *input, char c, int pos);

char	**lex(char *input, t_god *god_struct)
{
	int		i;
	char	*tmp;
	int		next_quote;

	if (!*input)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			tmp = insert_sub_quote(input, input[i], i);
			free_string(&input);
			input = tmp;
			next_quote = skip_quotes(input + i);
			if (next_quote == -1)
				return (free_string(&input), NULL);
			i += next_quote;
		}
		if (input[i] == ' ' || input[i] == '\t')
			input[i] = 26;
		i++;
	}
	return (split_input(input, god_struct));
}

static	char	**split_input(char *input, t_god *god_struct)
{
	int		i;
	int		operator_count;
	char	*tmp;
	char	**split_str;

	i = 0;
	while (input[i])
	{
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			operator_count = count_operators(input + i, input[i]);
			tmp = insert_sub(input, i);
			free_string(&input);
			input = tmp;
			i += operator_count;
		}
		i++;
	}
	split_str = ft_split(input, 26);
	free_string(&input);
	if (!split_str)
		return (NULL);
	return (expander(split_str, god_struct));
}

char	*insert_sub(char *input, int pos)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(sizeof(char), (ft_strlen(input) + 3));
	if (str)
	{
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
	}
	return (str);
}

char	*insert_sub_quote(char *input, char c, int pos)
{
	int		i;
	int		j;
	int		found;
	char	*str;

	i = 0;
	j = 0;
	found = 0;
	str = ft_calloc(sizeof(char), ft_strlen(input) + 3);
	if (!str)
		return (NULL);
	while (input[j])
	{
		if (input[j] == c && i >= pos)
		{
			if (++found < 3)
			{
				if (found == 1)
					str[i++] = 26;
				str[i++] = input[j++];
				if (found == 2)
					str[i++] = 26;
			}
		}
		str[i++] = input[j++];
	}
	return (str);
}
