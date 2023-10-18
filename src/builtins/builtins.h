/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:32:35 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/18 14:15:18 by Kekuhne          ###   ########.fr       */
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

#endif