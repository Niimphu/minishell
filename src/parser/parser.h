/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:09 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/14 18:13:39 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../minishell.h"

char	**lex(char *input);
bool	is_syntax_valid(t_list *parsed_list);
char	*invalid_syntax(t_list *lexer_list);

t_list	*create_lexer_list(char **input_array);
void	create_docs(t_list *parser_list, t_god *god_struct);

int		get_operator_id(char *operator_string);

int		next_command(char **str);
int		next_operator(char **str);
bool	contains_operator(char c);
//bool	ends_with_operator(char **array);
//int		count_quotes(char *str, char quotes);

char	get_operator(char *str);
int		skip_quotes(char *str);

#endif