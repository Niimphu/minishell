/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/30 13:10:23 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*expand_var(char *str, t_god *god_struct);

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
		trim_quotes(&split_str[i]);
		i++;
	}
	return (split_str);
}

static char	*expand_var(char *str, t_god *god_struct)
{
	int		i;
	int		var_count;
	char	*tmp;
	char	**split_str;
	char	*expanded;

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
	expanded = join_split(split_str, god_struct);
	return (free_string(&str), expanded);
}
