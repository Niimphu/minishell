/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/03 16:22:23 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char *replace_whitespaces(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '"' || str[i] == '\'')
		{
			i++;
			while(str[i] != '"'|| str[i] == '\'')
			{
				if (!str[i])
					return (NULL);
				i++;
			}
		}
		if (str[i] == ' ')
				str[i] = 26;
		i++;
	}
	return (str);
}

void	lexer(t_lexer *input)
{
	int i = 0;
	char **split_str;
	
	input->raw_input = replace_whitespaces(input->raw_input);
	split_str = ft_split(input->raw_input, 26);
	while (split_str[i])
	printf("%s\n", split_str[i++]);
}