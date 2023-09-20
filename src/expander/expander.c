/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/20 18:52:14 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

char	*expand_var(char *str, t_god *god_struct);
char	*join_split(char **split, t_god *god_struct);
char	*wow_much_function_name(char *str);
int		expansion_needed(char *str);
// "'$HOME'"
// trim quotes

char	**expander(char **split_str, t_god *god_struct)
{
	int		i;
	char	*tmp;

	i = 0;
	while (split_str[i])
	{
		if (expansion_needed(split_str[i]))
		{
			tmp = expand_var(split_str[i], god_struct);
			split_str[i] = tmp;
		}
		i++;
	}
	return (split_str);
}

int	expansion_needed(char *str)
{
	int		i;
	char	quote_char;
	int		var_i;

	i = 0;
	var_i = first_index_of(str + i, '$');
	while (str[i] && var_i != 0)
	{
		var_i = first_index_of(str + i, '$');
		if (str[i] == '\'' || str[i] == '"')
		{
			quote_char = str[i];
			if (quote_char == '"')
				i += skip_quotes(str + i);
			if(quote_char == '\'' && (var_i > first_index_of(str + i, quote_char)
				&& var_i < second_index_of(str + i, quote_char)))
				return (0);
		}
		i++;
	}
	return (1);
}

char	*expand_var(char *str, t_god *god_struct)
{
	int		i;
	int		var_count;
	char	*tmp;
	char	**split_str;

	i = 0;
	tmp = wow_much_function_name(str);
	str = tmp;
	while (str[i])
	{
		if (str[i] && str[i] == '$')
		{
			var_count = count_operators(str + i, str[i]);
			tmp = insert_sub(str, i);
			free_string(&str);
			str = tmp;
			i += var_count;
		}
		i++;
	}
	split_str = ft_split(str, 26);
	if (!split_str)
		return (free_string(&str), NULL);
	return (free_string(&str), join_split(split_str, god_struct));
}

char	*wow_much_function_name(char *str)
{
	int		i;
	char	*tmp;
	int		var_count;

	i = 0;
	var_count = count_char(str, '$');
	while (str[i] && var_count--)
	{
		while (str[i] && str[i] != '$')
			i++;
		if (str[i] && str[i] == '$')
		{
			i++;
			while (str[i] && ft_isalnum(str[i]))
				i++;
			if (str[i])
			{
				tmp = insert_sub(str, i);
				free_string(&str);
				str = tmp;
			}
		}
	}
	return (str);
}

char	*join_split(char **split, t_god *god_struct)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	str = ft_strdup("");
	if (!str)
		return (free(str), NULL);
	while (split[i])
	{
		if (split[i] && !ft_strcmp(split[i], "$"))
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
