/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/15 13:07:17 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*expand_var(char *str, t_god *god_struct);
char	*join_split(char **split, t_god *god_struct);
char	*wow_much_function_name(char *str);

char	**expander(char **split_str, t_god *god_struct)
{
	int	i;
	
	i = 0;
	while (split_str[i])
	{
		if (ft_strchr(split_str[i], '$'))
			split_str[i] = expand_var(split_str[i], god_struct);
		i++;
	}
	return (split_str);
}

char	*expand_var(char *str, t_god *god_struct)
{
	int		i;
	int		var_count;
	char	*tmp;
	char	**split_str;
	
	i = 0;
	str = wow_much_function_name(str);
	while (str[i])
	{
		if (str[i] == '$')
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
	if (split_str)
		str = join_split(split_str, god_struct);
	return (str);
}

char	*wow_much_function_name(char *str)
{
	int	i;
	int	var_count;

	i = 0;
	printf("Start: wow str = %s\n", str);
	var_count = count_char(str, '$');
	while (var_count--)
	{
		while (str[i] && str[i] != '$')
			i++;
		if (str[i] == '$')
		{
			i++;
			printf("after $ is found %c\n", str[i]);
			while(str[i] && ft_isalnum(str[i]))
				i++;
			printf("insert sub here %c\n", str[i]);
			if (str[i])
				str = insert_sub(str, i);
		}
	}
	printf("END: wow str = %s\n", str);
	return (str);
}

char	*join_split(char **split, t_god *god_struct)
{
	int	i;
	char *str;
	
	i = 0;
	str = "\0";
	while (split[i])
	{
		if (split[i] && !ft_strcmp(split[i], "$"))
		{
			i++;
			split[i] = get_var(split[i], god_struct);
			printf("split is %s\n", split[i]);
		}
		str = ft_strjoin(str, split[i]);
		if (!str)
			return (free_string_array(&split), NULL);
		i++;
	}
	return (str);
}
