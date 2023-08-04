/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/04 13:46:29 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_quotes(char *str, char qoutes)
{
	int	i;
	int	found_c;

	i = 0;
	found_c = 0;
	while (str[i] && str[i] != '|')
	{
		if (str[i] == qoutes)
			found_c++;
		i++;
	}
	return (found_c);
}

int skip_quotes(char *str)
{
	int	i;
	char c;
	
	i = 1;
	c = str[0];
	while(str[i])
	{
		if (str[i] == c && !count_quotes(str + i + 1, c))
			return (i);
		else
			i++;
	}
	perror("Didnt find closing quotes");
	return (0);
}

char *replace_whitespaces(char *str)
{
	int		i;

	i = 0;
	if ((ft_strchr(str, '"') && (count_quotes(str, '"') % 2 == 0))
		|| (ft_strchr(str, '\'') && (count_quotes(str, '"') % 2 == 0)))
	{
		while(str[i])
		{
			if(str[i] == '"' || str[i] == '\'')
			{
				i += skip_quotes(str + i);
					i++;
			}
			if (str[i] == ' ')
				str[i] = 26;
			i++;
		}
	}
	else
		return ("Close your quotes brav");
	return (str);
}

void	lexer(t_lexer *input)
{
	int i;
	char **split_str;
	
	i = 0;
	input->raw_input = replace_whitespaces(input->raw_input);
	split_str = ft_split(input->raw_input, 26);
	while (split_str[i])
		printf("%s\n", split_str[i++]);
}