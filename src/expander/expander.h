/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:37:22 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/05 21:31:50 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../../minishell.h"
# include "../parser/parser.h"

char	*join_split(char **split, t_god *god_struct);
char	*wow_much_function_name(char *str);
bool	expansion_needed(char *str);
char	**trim_quotes(char ***str);

#endif