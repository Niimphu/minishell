/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/12 15:43:16 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*expand_var(char *str, t_god *god_struct);
char **cleanup_split(char **split);
char *catonate_whitespace(char **new_split, int index);

char	**expander(char **split_str, t_god *god_struct)
{
	int		i;
	int		single_qoute;
	char	*tmp;

	i = 0;
	single_qoute = -1;
	while (split_str[i])
	{
		if (expansion_needed(split_str, i))
		{
			tmp = expand_var(split_str[i], god_struct);
			split_str[i] = tmp;
		}
		i++;
	}
	trim_quotes(&split_str);
	if (!split_str)
		return (NULL);
	return (cleanup_split(split_str));
}

char	*insert_sub_varlen(char *var)
{
	int		i;
	char	*new_var;
	
	i = 0;
	while (var[i])
	{
		if (var[i] == '$')
		{
			new_var = insert_sub2(var, i);
			var = new_var;
			i += 3;
			if (var[i] && (var[i] == '_' || ft_isalpha(var[i])))
			{
				i++;
				while (var[i] && ft_isalnum(var[i]))
					i++;
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
	i = 0;
	printf("varsting = ");
	while(var[i])
	{
		if (var[i] == 26)
			printf("|SUB|");
		else
			printf("%c", var[i]);
		i++;
	}
	printf("\n");
	return (var);
}

static char	*expand_var(char *str, t_god *god_struct)
{
	int		i;
	char	*tmp;
	char	**split_str;

	i = 0;
	tmp = insert_sub_varlen(str);
	str = tmp;
	split_str = ft_split(str, 26);
	if (!split_str)
		return (free_string(&str), NULL);
	i = 0;
	while (split_str[i])
		printf("split_str = %s\n", split_str[i++]);
	return (join_split(split_str, god_struct));
}

char **cleanup_split(char **split)
{
	int	i;
	int j;
	char **new_split;

	i = 0;
	j = 0;
	while(split[i])
	{
		if (*split[i] != '\0')
			j++;
		i++;
	}
	new_split = ft_calloc(sizeof(char *), j + 1);
	i = 0;
	j = 0;
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

char *catonate_whitespace(char **new_split, int index)
{
	char *tmp;

	tmp = NULL;
	if (!new_split[index])
		return (NULL);
	if (*new_split[index] == ' ')
	{
		tmp = ft_strjoin(new_split[index - 1], " ");
		free_string(&new_split[index - 1]);
	}
	return (tmp);
}
