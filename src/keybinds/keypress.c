/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:45:10 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/06 14:46:07 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	clear_input(int signum, siginfo_t *info, void *context);

void	check_ctrl_c(void)
{
	struct sigaction	ctrl_c_pressed;

	ctrl_c_pressed.sa_sigaction = clear_input;
	ctrl_c_pressed.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &ctrl_c_pressed, NULL);
}

void	clear_input(int signum __attribute__((unused)),
	siginfo_t *info __attribute__((unused)), void *context __attribute__((unused)))
{
	printf("^C\n");

}
