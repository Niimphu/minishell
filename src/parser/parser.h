/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:09 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/18 22:05:14 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../minishell.h"

# define SKIP 1

char	**lex(char *input, t_god *god_struct);
char	*invalid_syntax(t_list *lexer_list);

t_list	*create_lexer_list(char **input_array);
t_list	*convert_commands(t_list *parser_list);
t_file	*file_away(t_lexer *current, t_lexer *next);
void	create_file_list(t_list *parser_list, t_list *lexer_list);

int		get_operator_id(char *operator_string);

int		skip_quotes(const char *str);
char	*insert_sub(char *input, int pos);

#endif