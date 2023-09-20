/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:48:27 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/20 16:45:27 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	skip_quotes(const char *str)
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
	write(2, "Unclosed quotes found: ", 23);
	write(2, &c, 1);
	write(2, "\n", 1);
	return (-1);
}

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
	return (0);
}

int	second_index_of(char *str, char c)
{
	int	i;
	int	found;
	
	i = 0;
	found = 0;
	while (str[i])
	{
		if (str[i] == c)
			found++;
		if (found == 2)
			return (i);
		i++;
	}
	return (0);
}

char	*insert_sub_left(char *input, int pos)
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
	printf("found pos: %d, inserting at %d\n",pos, i);
	str[i++] = 26;
	while (input[i - 1] == input[pos])
	{
		str[i] = input[i - 1];
		i++;
	}
	while (input[i - 1])
	{
		str[i] = input[i - 1];
		i++;
	}
	return (str);
}

char	*insert_sub_right(char *input, int pos)
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
	while (input[i] == input[pos])
	{
		str[i] = input[i];
		i++;
	}
	printf("found pos: %d, inserting at %d\n", pos, i);
	str[i++] = 26;
	while (input[i - 1])
	{
		str[i] = input[i - 1];
		i++;
	}
	return (str);
}
