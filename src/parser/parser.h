/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:09 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/13 17:44:56 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../minishell.h"

char	**lex(char *input, t_god *god_struct);
bool	is_syntax_valid(t_list *parsed_list);

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