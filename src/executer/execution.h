/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:37:25 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/06 15:03:12 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../file_managers/files.h"
# include "../signals/signals.h"

t_list	*create_execution_list(t_list *parser_list);

int		pipe_up(t_list *exec_list);
void	find_exec(t_exec *node, char **env);
int		close_all_pipes(t_list *exec_list);
bool	is_dir(char *cmd);

void	print_exec_list(t_list *exec_list);

#endif