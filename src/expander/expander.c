/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/05 21:30:51 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*expand_var(char *str, t_god *god_struct);
/* static char	**handle_qoutes(char **split_str, int size); */
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
		printf("split_str at start of expander = %s\n", split_str[i++]);
	i = 0;
	while (split_str[i])
	{
		if (split_str[i][0] == '\'')
			single_qoute *= -1;
		if (ft_strchr(split_str[i], '$') && single_qoute < 0)
		{
			tmp = expand_var(split_str[i], god_struct);
			split_str[i] = tmp;
		}
		i++;
	}
	trim_quotes(&split_str);
	i = 0;
	while (split_str[i])
		printf("split_str at end of lexer = %s\n", split_str[i++]);
	return (cleanup_split(split_str));
}

static char	*expand_var(char *str, t_god *god_struct)
{
	int		i;
	char	*tmp;
	char	**split_str;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = insert_sub2(str, i++);
			str = tmp;
		}
		i++;
	}
	split_str = ft_split(str, 26);
	i = 0;
	while (split_str[i])
		printf("before join_split %s\n", split_str[i++]);
	if (!split_str)
		return (free_string(&str), NULL);
	return (free_string(&str), join_split(split_str, god_struct));
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
		if (split[i][0] == '\0')
			j++;
		i++;
	}
	new_split = ft_calloc(sizeof(char *), j + 1);
	i = 0;
	j = 0;
	while (split[i])
	{
		if (split[i][0] != '\0' && split[i][0] != ' ')
		{
			new_split[j] = ft_strdup(split[i]);
			if (!new_split[j])
				return (free_string_array(&split), NULL);
			if (split[i + 1] && split[i + 1][0] == ' ')
				new_split[j] = catonate_whitespace(split, i + 1);
			j++;
		}
		i++;
	}
	new_split[j] = NULL;
	i = 0;
	while (new_split[i])
		printf("cleanuo array : %s\n", new_split[i++]);
	
	return (free_string_array(&split), new_split);
}

char *catonate_whitespace(char **new_split, int index)
{
	char *tmp;

	tmp = NULL;
	if (!new_split[index])
		return (NULL);
	if (new_split[index][0] == ' ')
	{
		tmp = ft_strjoin(new_split[index - 1], " ");
		free_string(&new_split[index - 1]);
	}
	return (tmp);
}