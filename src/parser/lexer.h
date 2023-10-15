/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:13:55 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/15 13:14:15 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../../minishell.h"

int		next_is_operator(char **split_str, int index);



int		skip_quotes(const char *str, int i);

bool	set_trim(char **split_string, int i, bool trim);

#endif