/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:59:29 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/06 15:05:50 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "../../minishell.h"

void	await_signals(void);
void	await_child_signals(void);
void	set_signal_error(t_god *god_struct);

#endif