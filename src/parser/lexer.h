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

int		skip_quotes(const char *str, int i);

char	*insert_sub1(char *input, int pos);
char	*insert_sub2(char *input, int pos);

#endif