/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:02:19 by aozmen            #+#    #+#             */
/*   Updated: 2023/06/15 18:04:05 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCR: Split string, with specified character as delimiter,
into an array of strings
Allocates (with malloc(3)) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter. The array must be
ended by a NULL pointer.

EXTFUNCT: malloc, free

PARAM:
s: The string to be split.
c: The delimiter character.

RETURNVALUE:
The array of new strings resulting from the split.
NULL if the allocation fails.

VRBL:
i: counter to iterate over the characters of the input string s. 
word: flag to indicate whether the current character belongs to a word.
Sets to 1 when a word is encountered and 0 when "_".
j: counter to iterate over the array of strings that will contain
the split words.
index: variable to store the starting position of a word in the input string.
Sets to -1 when a separator character is encountered and reset to the current 
position when a word is encountered. 
split: pointer to a pointer to a char, which is used to store the dynamically
allocated array of strings that will contain the split words.
*/

#include "../libft.h"

static int	words_count(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			word = 1;
			i++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (i);
}

static void	ft_free(char **split, int i)
{
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

int	split_loop(const char *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = word_dup(s, index, i);
			if (!split[j])
				return (-1);
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	split = malloc((words_count(s, c) + 1) * sizeof(char *));
	if (!s || !(split))
		return (NULL);
	if (split_loop(s, c, split) == -1)
	{
		ft_free(split, 0);
		return (NULL);
	}
	return (split);
}
