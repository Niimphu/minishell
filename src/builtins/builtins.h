/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:32:35 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/19 16:34:35 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../../minishell.h"

int		env(char **cmd, t_god *god_struct);
int		export(char **cmd, t_god *god_struct);
int		echo(char **cmd, t_god *god_struct);
int		unset(char **cmd, t_god *god_struct);
int		pwd(void);
int		cd(char *dir, t_god *god_struct);

void	exit_minishell(char **cmd, t_god *god_struct);

char	**alloc_and_assign_new_env(char **original_env, char *cmd);
int		set_env_condition(char *cmd, char *env);

#endif