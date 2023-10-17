/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/15 18:25:07 by Kekuhne          ###   ########.fr       */
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
	return (free_string(&str), join_split(split_str, god_struct));
}
