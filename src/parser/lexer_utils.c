/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:48:27 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/11 14:26:11 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	get_operator(char *str)
{
	if (ft_strchr(str, '|'))
		return ('|');
	else if (ft_strchr(str, '<'))
		return ('<');
	else if (ft_strchr(str, '>'))
		return ('>');
	else
		return (0);
}

int	skip_quotes(char *str)
{
	int		i;
	char	c;

	i = 1;
	c = str[0];
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	perror("Unclosed quotes found");
	return (0);
}
