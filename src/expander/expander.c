/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/15 13:16:22 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "../parser/lexer.h"

static char	*expand_var(char *str, t_god *god_struct);
static int	expansion_needed(char **split_str, int index);
char		**cleanup_split(char **split);

/**
 * @brief Iterates throught string array and attemps
 * to substitute Variables with their Value in god_struct->env. 
 * If no Value is found the string array index is deleted.
 * Then removes the outer-quotes.
 * @return joined string from split_str with expanded variables
 * and trimed outer qoutes;
 */
char	**expander(char **split_str, t_god *god_struct)
{
	int		i;
	char	*tmp;

	i = 0;
	while (split_str[i])
	{
		printf("split_str[i] %s\n", split_str[i]);
		if (expansion_needed(split_str, i))
		{
			tmp = expand_var(split_str[i], god_struct);
			split_str[i] = tmp;
		}
		i++;
	}
//	trim_quotes(&split_str);
	if (!split_str)
		return (NULL);
	return (cleanup_split(split_str));
}

/**
 * @brief checks if index of split_str contains a Variable.
 * If so checks position of opening and closing quotes.
 * Based on the position of index to opening and closing quotes return 1 or 0;
 * @return 0 if no var is found or if the var is inside single quotes;
 * 1 if var is not inside quotes or inside double quotes;
*/
static int	expansion_needed(char **split_str, int index)
{
	int	i;
	int	quote_close;

	i = 0;
	if (!ft_strchr(split_str[index], '$'))
		return (0);
	while (split_str[i])
	{
		if (i < index && (*split_str[i] == '\'' || *split_str[i] == '"'))
		{
			quote_close = verify_closing_qoutes(split_str, i, *split_str[i]);
			if (quote_close < index)
			{
				i = quote_close + 1;
				continue ;
			}
			else if (*split_str[quote_close] == '\'')
				return (0);
			else if (*split_str[quote_close] == '"')
				return (1);
			i = quote_close;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Inserts substitute character around $ and at the end of var name.
 * Splits str on those characers, expands var`s and joines string togethaaaa.
 * @return expanded variable string
*/
static char	*expand_var(char *str, t_god *god_struct)
{
	int		i;
	char	*tmp;
	char	**split_str;

	i = 0;
	tmp = insert_sub_varlen(str, 0);
	str = tmp;
	split_str = ft_split(str, 26);
	if (!split_str)
		return (free_string(&str), NULL);
	return (free_string(&str), join_split(split_str, god_struct));
}

/**
 *@brief Counts string array index, excluding empty ones. 
 *returns -1 if size = 0 to only allocate memory for NULL pointer;
*/
int	new_split_size(char **split)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (split[i])
	{
		if (*split[i] != '\0')
			size++;
		i++;
	}
	return (size);
}

/**
 * @brief creates new string array, skipping empty entrys of split;
*/
char	**cleanup_split(char **split)
{
	int		i;
	int		size;
	int		j;
	char	**new_split;

	i = 0;
	j = 0;
	size = new_split_size(split);
	if (size == 0)
		return (free_string_array(&split), NULL);
	new_split = ft_calloc(sizeof(char *), size + 1);
	while (split[i])
	{
		if (*split[i] != '\0')
		{
			new_split[j] = ft_strdup(split[i]);
			if (!new_split[j])
				return (free_string_array(&split), NULL);
			j++;
		}
		i++;
	}
	new_split[j] = NULL;
	return (free_string_array(&split), new_split);
}
