/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:09 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/24 18:33:09 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../../minishell.h"

char	*replace_whitespaces(char *str);
int		skip_quotes(char *str);

int		count_quotes(char *str, char quotes);

#endif