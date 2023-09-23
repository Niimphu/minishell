/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:08:11 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/24 00:08:11 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include "../../minishell.h"

void	open_heredocs(t_list *parsed_list);
void	open_files(t_list *parsed_list);

#endif