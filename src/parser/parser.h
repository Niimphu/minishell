/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:09 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/05 17:50:22 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../minishell.h"

char		**lex(char *input, t_god *god_struct);
char		*invalid_syntax(t_list *lexer_list);

t_list		*create_lexer_list(char **input_array);
t_list		*convert_commands(t_list *parser_list);
t_parser	*file_away(t_parser *parser_node, t_lexer *current, t_lexer *next);

int			get_operator_id(char *operator_string);

//int			skip_quotes(const char *str);
char		**cleanup_split(char **split);

#endif