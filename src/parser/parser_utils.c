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
