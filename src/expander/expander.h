/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:37:22 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/09 13:33:52 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../../minishell.h"
# include "../parser/parser.h"

char	*join_split(char **split, t_god *god_struct);
char	*wow_much_function_name(char *str);
int		expansion_needed(char **str, int index);
void	trim_quotes(char ***str);
int		verify_closing_qoutes(char **split, int i, char qoute_found);

#endif