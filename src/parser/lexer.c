/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/20 19:24:26 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**split_input(char *input, t_god *god_struct);

char	**lex(char *input, t_god *god_struct)
{
	char	**split_str;
	int		i;
	int		next_quote;

	if (!*input)
		return (free_string(&input), NULL);
	i = 0;
	next_quote = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
		{
			next_quote = skip_quotes(input + i);
			i += next_quote;
		}
		if (next_quote < 0)
			return (NULL);
		if (input[i] == ' ' || input[i] == '\t')
			input[i] = 26;
		i++;
	}
	split_str = split_input(input, god_struct);
	return (split_str);
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
		if (input[i] == '"' || input[i] == '\'')
			i += skip_quotes(input + i);
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
	while (input[i - 2])
	{
		str[i] = input[i - 2];
		i++;
	}
	return (str);
}
