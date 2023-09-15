/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:16:24 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/13 16:24:08 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exit_minishell(t_god *god_struct)
{
	free_god_struct(&god_struct);
	clear_history();
	exit (0);
}
