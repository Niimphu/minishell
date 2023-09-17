/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:09 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/16 18:27:39 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../minishell.h"

# define SKIP 1

char	**lex(char *input, t_god *god_struct);
char	*invalid_syntax(t_list *lexer_list);

t_list	*create_lexer_list(char **input_array);
void	create_docs(t_list *parser_list, t_god *god_struct);
void	file_away(t_list *files, t_lexer *operator, t_lexer *word);

int		get_operator_id(char *operator_string);

int		skip_quotes(const char *str);
char	*insert_sub(char *input, int pos);

#endif