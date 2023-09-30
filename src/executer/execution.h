/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:37:25 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/30 13:02:52 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../file_managers/files.h"

t_list	*create_execution_list(t_list *parser_list);

int		pipe_up(t_list *exec_list);

void	print_exec_list(t_list *exec_list);

#endif