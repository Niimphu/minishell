/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:09 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/19 13:04:52 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../minishell.h"
# include "lexer.h"

char		**lex(char *input, t_god *god_struct);
char		*invalid_syntax(t_list *lexer_list);

t_list		*create_lexer_list(char **input_array);
t_list		*convert_commands(t_list *parser_list);
t_parser	*file_away(t_parser *parser_node, t_lexer *current, t_lexer *next);

int			get_operator_id(char *operator_string);
void		trim_quotes(t_list *lexer_list);

char		**cleanup_split(char **split);

#endif