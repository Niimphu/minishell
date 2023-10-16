/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:48:27 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/15 14:57:56 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	first_index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (FAIL);
}

int	skip_quotes(const char *str, int i)
{
	char	c;

	c = str[i++];
	while (str[i] && str[i] != c)
		i++;
	if (str[i] && str[i] == c)
		return (i);
	ft_putstr_fd("minishelf: unclosed quote found\n", 2);
	return (FAIL);
}
