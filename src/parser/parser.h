/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:09 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/20 16:24:16 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../minishell.h"

# define SKIP 1

char		**lex(char *input, t_god *god_struct);
char		*invalid_syntax(t_list *lexer_list);

t_list		*create_lexer_list(char **input_array);
t_list		*convert_commands(t_list *parser_list);
t_parser	*file_away(t_parser *parser_node, t_lexer *current, t_lexer *next);

int			get_operator_id(char *operator_string);

int			skip_quotes(const char *str);
char		*insert_sub(char *input, int pos);


int			first_index_of(char *str, char c);
int			second_index_of(char *str, char c);
char	*insert_sub_right(char *input, int pos);
char	*insert_sub_left(char *input, int pos);
#endif