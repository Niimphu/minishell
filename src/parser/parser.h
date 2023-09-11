/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:33:09 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/11 14:31:16 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../minishell.h"

char	**lex(char *input);
bool	is_syntax_valid(t_list *parsed_list);

void	create_docs(t_list *parser_list, t_god *god_struct);

int		count_quotes(char *str, char quotes);
int		next_command(char **str);
int		next_operator(char **str);
bool	contains_operator(char c);
bool	ends_with_operator(char **array);

char	get_operator(char *str);
int		skip_quotes(char *str);

#endif