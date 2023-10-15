/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/15 13:10:29 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static char	**split_input(char *input);

char	**lex(char *input, t_god *god_struct)
{
	int		i;
	char	*tmp;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			i = skip_quotes(input, i);
			if (i == FAIL)
				return (NULL);
		}
		if (input[i] == ' ')
			input = insert_sub1(input, i++);
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			tmp = insert_sub2(input, i++);
			if (input[i] == input[i - 1])
				i++;
			input = tmp;
		}
		i++;
	}
	return (expander(split_input(input), god_struct));
}

static char	**split_input(char *input)
{
	int		i;
	bool	trim;
	char	**split_str;
	char	*tmp;

	i = 0;
	trim = true;
	split_str = ft_split(input, 26);
	if (!split_str)
		return (NULL);
	while (split_str[i])
	{
		if (trim == true || next_is_operator(split_str, i)
			|| split_str[i][0] == '|' || split_str[i][0] == '<'
			|| split_str[i][0] == '>')
		{
			tmp = ft_strtrim(split_str[i], " ");
			free_string(&split_str[i]);
			split_str[i] = tmp;
			trim = set_trim(split_str, i, trim);
		}
		i++;
	}
	return (free(input), split_str);
}

char	*insert_sub2(char *input, int pos)
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
	else
		return (NULL);
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
/* 
int	next_is_operator(char **split_str, int index)
{
	int	next_index;

	next_index = index + 1;

	if (!split_str[next_index])
		return (0);
	if (split_str[next_index][0] == '|' || split_str[next_index][0] == '<' || split_str[next_index][0] == '>')
		return (1);
	else
		return (0);
}
 */