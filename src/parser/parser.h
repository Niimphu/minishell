/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:09 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/06 23:42:59 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../minishell.h"

char	*lex(char *str);
bool	is_syntax_valid(t_list *parsed_list);

t_list	*create_lexer_list(char **input_array);
void	create_docs(t_list *parser_list, t_god *god_struct);

int		get_operator_id(char *operator_string);

int		next_command(char **str);
int		next_operator(char **str);
bool	contains_operator(char c);
//bool	ends_with_operator(char **array);
//int		count_quotes(char *str, char quotes);

#endif