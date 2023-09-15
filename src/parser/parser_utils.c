/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:31:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/14 18:13:39 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	contains_operator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (true);
	return (false);
}

int	next_command(char **str)
{
	int	i;

	i = 0;
	while (str[i] && !contains_operator(str[i][0]))
		i++;
	if (str[i])
		i++;
	return (i);
}

int	next_operator(char **str)
{
	int	i;

	i = 0;
	while (str[i] && !contains_operator(str[i][0]))
		i++;
	return (i);
}

int	get_operator_id(char *operator_string)
{
	if (!ft_strncmp("|", operator_string, 2))
		return (PIPE);
	if (!ft_strncmp("<", operator_string, 2))
		return (INPUT);
	if (!ft_strncmp(">", operator_string, 2))
		return (OUTPUT);
	if (!ft_strncmp("<<", operator_string, 3))
		return (HEREDOC);
	if (!ft_strncmp(">>", operator_string, 3))
		return (APPEND);
	else
		return (BAD_OPERATOR);
}

//bool	ends_with_operator(char **array)
//{
//	int	i;
//
//	i = 0;
//	while (array[i + 1])
//		i++;
//	return (contains_operator(*array[i]));
//}

//int	count_quotes(char *str, char quotes)
//{
//	int	i;
//	int	quote_count;
//
//	i = 0;
//	quote_count = 0;
//	while (str[i])
//	{
//		if (str[i] == quotes)
//			quote_count++;
//		i++;
//	}
//	return (quote_count);
//}
