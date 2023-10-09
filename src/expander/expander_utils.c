/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:36:44 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/05 21:36:00 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	**trim_quotes(char ***str);

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
		if (split[i] && split[i][0] != ' ')
		{
			tmp = ft_strjoin(str, split[i]);
			if (!tmp)
				return (free_string_array(&split), NULL);
			free_string(&str);
			str = tmp;
		}
		printf("after join split = %s\n", split[i]);
		i++;
	}
	return (free_string_array(&split), str);
}

//write a function that steps throught the array checks for qoutes and removes outerqoutes from array;
//should return error when no closing qoutes are found;
//possible swap closing with whitespace if one follows it
//maybe join left over qoutes with str;

char	**trim_quotes(char ***str)
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
