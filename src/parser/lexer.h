/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:13:55 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/11 16:13:55 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../../minishell.h"

int		next_is_operator(char **split_str, int index);

char	*insert_sub1(char *input, int pos);
char	*insert_sub2(char *input, int pos);

bool	set_trim(char **split_string, int i, bool trim);

#endif