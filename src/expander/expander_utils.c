/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:36:44 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/15 13:08:48 by Kekuhne          ###   ########.fr       */
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
char	*insert_sub_varlen(char *var, int i)
{
	char	*new_var;

	while (var[i])
	{
		if (var[i] == '$' && var[i + 1])
		{
			new_var = insert_sub2(var, i);
			var = new_var;
			i += 3;
			if (var[i] && (var[i] == '_' || ft_isalpha(var[i])))
			{
				while (var[i] && ft_isalnum(var[++i]))
					;
				new_var = insert_sub1(var, i - 1);
				var = new_var;
			}
			else
			{
				new_var = insert_sub1(var, i);
				var = new_var;
			}
		}
		i++;
	}
	return (var);
}

int	verify_closing_qoutes(char **split, int i, char qoute_found)
{
	i++;
	while (split[i])
	{
		if (*split[i] == qoute_found)
			return (i);
		i++;
	}
	return (0);
}

/**
* @brief Interates throught array of strings and sets outer qoutes to '\0';
* @return none;
*/
void	trim_quotes(char ***str)
{
	int		i;
	int		qoute_close;
	char	**split;

	i = 0;
	split = *str;
	while (split[i])
	{
		if (*split[i] == '\'' || *split[i] == '"')
		{
			qoute_close = verify_closing_qoutes(split, i, *split[i]);
			if (qoute_close == 0)
				return (free_string_array(str));
			*split[i] = '\0';
			*split[qoute_close] = '\0';
			i = qoute_close;
		}
		i++;
	}
}

int	expansion_needed(char **split_str, int index)
{
	int i;
	int quote_close;
	
	i = 0;
	if (!ft_strchr(split_str[index], '$'))
		return (0);
	else
	{
		ft_putstr_fd("expand here you donut\n", 2);
		return (0);
	}
	//printf("index at %d\n", index);
	while (split_str[i])
	{
		if (*split_str[i] == '\'' || *split_str[i] == '"')
		{
			//printf("found qoute %c %d\n", *split_str[i], i);
			if (i > index)
			{
				//printf("i[%d] greater than index[%d]\n", i, index);
				i++;
				continue ;
			}
			quote_close = verify_closing_qoutes(split_str, i, *split_str[i]);
			//printf("closing qoute %c %d\n", *split_str[quote_close], quote_close);
			if (quote_close < index)
			{
				//printf("closing qoute *%c*[%d] before var at %d\n", *split_str[quote_close], quote_close, index);
				i = quote_close + 1;
				continue ;
			}
			else if (*split_str[quote_close] == '\'' && i < index)
			{
				//printf("var inside single qoutes(closing qoute at %d),var at %d no expansion needed\n", quote_close, index);
				return (0);
			}
			else if (i < index && *split_str[quote_close] == '"')
			{
				//printf("var inside double qoutes(closing qoute at %d), var at %d\n", quote_close, index);
				return (1);
			}
			i = quote_close;
		}
		i++;
	}
	//printf("var not inside qoutes, expanding\n");
	return (1);
}

