/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:36:44 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/17 22:07:13 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

/**
 * @brief creates new str from split. By Joining each index of split, skips $
 * and sets env value for split[i]. If no Value is found sets
 * split[i] as empty;
 * @return new joined str from split with expanded vars;
*/
char	*join_split(char **split, t_god *god_struct)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	str = ft_strdup("");
	while (split[i])
	{
		if (split[i] && split[i + 1] && !ft_strcmp(split[i], "$"))
		{
			i++;
			split[i] = get_var(split[i], god_struct);
		}
		tmp = ft_strjoin(str, split[i]);
		if (!tmp)
			return (free_string_array(&split), NULL);
		free_string(&str);
		str = tmp;
		i++;
	}
	return (free_string_array(&split), str);
}

/**
*@brief Inserts substitute char around $.
*Inserts substitute char at end of variable name.
*The End of Varible is a non-alphanumerical char.
*@return Cpy of var with inserted substitute characters.
*/
static char	get_quote(char *var, int i, char quote);

char	*insert_sub_varlen(char *var, int i)
{
	char	quote;

	quote = 0;
	while (var[i])
	{
		if (var[i] == '\'' || var[i] == '"')
			quote = get_quote(var, i, quote);
		if (var[i] == '$' && (var[i + 1] == '_' || ft_isalpha(var[i + 1])) && quote != '\'')
		{
			var = insert_sub2(var, i);
			i += 3;
			if (var[i] && (var[i] == '_' || ft_isalpha(var[i])))
			{
				while (var[i] && ft_isalnum(var[++i]))
					;
				var = insert_sub1(var, i - 1);
			}
			else
				var = insert_sub1(var, i);
		}
		i++;
	}
	return (var);
}

static char	get_quote(char *var, int i, char quote)
{
	if (quote == 0)
		return (var[i]);
	else if (quote == var[i])
		return (0);
	return (quote);
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
