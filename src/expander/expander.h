/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:37:22 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/25 17:37:22 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../../minishell.h"
# include "../parser/parser.h"

char	*join_split(char **split, t_god *god_struct);
char	*wow_much_function_name(char *str);
bool	expansion_needed(char *str);
char	*trim_quotes(char **str);

#endif