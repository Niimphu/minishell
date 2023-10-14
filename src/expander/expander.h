/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:37:22 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/14 16:14:18 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../../minishell.h"
# include "../parser/parser.h"

char	*join_split(char **split, t_god *god_struct);
void	trim_quotes(char ***str);
int		verify_closing_qoutes(char **split, int i, char qoute_found);
char	*insert_sub_varlen(char *var, int i);
char	*create_clean_var_string(char *split, char *tmp,
			int var_len, t_god *god_struct);
char	**cleanup_split(char **split);

#endif