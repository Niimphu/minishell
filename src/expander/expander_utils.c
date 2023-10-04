/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:36:44 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/03 16:50:45 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

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
		if (split[i] && !ft_strcmp(split[i++], "$"))
			split[i] = get_var(split[i], god_struct);
		if (split[i])
		{
			tmp = ft_strjoin(str, split[i]);
			if (!tmp)
				return (free_string_array(&split), NULL);
			free_string(&str);
			str = tmp;
		}
		i++;
	}
	return (free_string_array(&split), str);
}

bool	expansion_needed(char *str)
{
	if (!ft_strchr(str, '$'))
		return (false);
	else if (ft_strchr(str, '$') && !ft_strchr(str, '\''))
		return (true);
	else if (ft_strchr(str, '$') && ft_strchr(str, '\''))
	{
		if (first_index_of(str, '"') < first_index_of(str, '\'')
			&& second_index_of(str, '"') > second_index_of(str, '\''))
			return (true);
	}
	return (false);
}

char	*trim_quotes(char **str)
{
	char	*c;
	char	*tmp;

	tmp = NULL;
	c = ft_substr(*str, 0, 1);
	if (!c)
		return (NULL);
	if (c[0] == '\'' || c[0] == '"')
	{
		tmp = ft_strtrim(*str, c);
		if (!tmp)
			return (NULL);
		free_string(str);
		*str = tmp;
	}
	return (free_string(&c), *str);
}
