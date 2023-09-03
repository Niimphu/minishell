/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_build_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:23:50 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/30 16:36:53 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	pwd_build_in(t_envp *tools)
{
	int	i;

	i = 0;
	while (tools->env[i])
	{
		if (!strncmp(tools->env[i], "PWD=", 4))
		{
			printf("%s\n", tools->env[i] + 4);
			break ;
		}
		i++;
	}
	return (0);
}