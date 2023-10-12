/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:36:44 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/12 15:03:12 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	one_white_space_strlen(char	*split)
{
	int	i;
	int	skip_white_space;
	
	i = 0;
	skip_white_space = 0;
	while (split[i + skip_white_space])
	{
		if (split[i + skip_white_space - 1] == ' ')
			skip_white_space++;
		else
			i++;
	}
	return (i);
}

char	*create_clean_var_string(char *split, char *tmp, int var_len, t_god *god_struct)
{
	int		split_len;
	char	*new_var_str;
	char	*var;

	split_len = ft_strlen(split);
	printf("here %s\n", split);
	var = get_var(tmp, god_struct);
	if (var && var_len < split_len)
	{
		tmp = ft_substr(split, var_len, split_len);
		new_var_str = ft_strjoin(var, tmp);
		return (free_string(&var), free_string(&tmp), new_var_str);
	}
	else
		return (var);
}

char	*insert_var_to_str(char *split, t_god *god_struct)
{
	int		i;
	char	*tmp;
	char	*var;
	
	i = 0;
	while(split[i] == '_' || ft_isalnum(split[i]))
		i++;
	tmp = ft_substr(split, 0, i);
	if (!tmp)
		return (free_string(&split), NULL);
	var = create_clean_var_string(split, tmp, i, god_struct);
	return (free_string(&split), var);
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
		
		if (split[i] && split[i + 1] && !ft_strcmp(split[i], "$"))
		{
			i++;
			split[i] = insert_var_to_str(split[i], god_struct);
		}
		if (split[i] && *split[i] != ' ')
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

int	verify_closing_qoutes(char **split, int i, char qoute_found)
{
	i++;
	while (split[i])
	{
		if (*split[i] == qoute_found)
			return (i);
		i++;
	}
	ft_putstr_fd("Missing Closing qoute :`", 2);
	ft_putchar_fd(qoute_found, 2);
	ft_putstr_fd(";\n", 2);
	return (0);
}

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
				return(free_string_array(str));
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
	while (split_str[i])
	{
		if (i < index && (*split_str[i] == '\'' || *split_str[i] == '"'))
		{
			quote_close = verify_closing_qoutes(split_str, i, *split_str[i]);
			if (quote_close < index)
			{
				i = quote_close + 1;
				continue ;
			}
			else if (*split_str[quote_close] == '\'')
				return (0);
			else if (*split_str[quote_close] == '"')
				return (1);
			i = quote_close;
		}
		i++;
	}
	return (1);
}