/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:32:35 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/16 21:32:35 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../../minishell.h"

int		env(char **cmd, t_god *god_struct);
int		export(char **cmd, t_god *god_struct);
int		echo(char **cmd);
int		unset(char **cmd, t_god *god_struct);
int		pwd(t_god *god_struct);
int		cd(char *dir, t_god *god_struct);
void	exit_minishell(char **cmd, t_god *god_struct);

#endif