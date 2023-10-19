/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/19 16:36:38 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*expand_var(char *str, t_god *god_struct);
static int	expansion_needed(char *split_str);

char	**expander(char **split_str, t_god *god_struct)
{
	int		i;
	char	*temp;

	i = 0;
	if (!split_str)
		return (NULL);
	while (split_str[i])
	{
		if (expansion_needed(split_str[i]))
		{
			temp = expand_var(split_str[i], god_struct);
			split_str[i] = temp;
		}
		i++;
	}
	if (new_split_size(split_str) == 0 && ft_strlen(*split_str) == 0)
		return (free_string_array(&split_str), NULL);
	return (split_str);
}

static int	expansion_needed(char *split_str)
{
	int		i;
	bool	expand;

	i = 0;
	expand = false;
	if (!ft_strchr(split_str, '$'))
		return (0);
	while (split_str[i])
	{
		if (split_str[i] == '"')
			expand = !expand;
		if (split_str[i] == '\'' && !expand)
			i = skip_quotes(split_str, i);
		if (split_str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

static char	*expand_var(char *str, t_god *god_struct)
{
	char	*tmp;
	char	**split_str;

	tmp = insert_sub_varlen(str, 0);
	str = tmp;
	split_str = ft_split(str, 26);
	if (!split_str)
		return (free_string(&str), NULL);
	free_string(&str);
	return (join_split(split_str, god_struct));
}
