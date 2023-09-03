/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:23:50 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/03 16:23:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	pwd(t_god *tools)
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
