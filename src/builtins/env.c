/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:39:16 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/19 16:29:10 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	env(char **cmd, t_god *god_struct)
{
	int		i;
	t_god	*ptr;

	i = 0;
	if (!cmd[1])
	{
		if (!god_struct->env)
			return (0);
		ptr = god_struct;
		while (ptr->env[i])
		{
			if (ft_strcmp(ptr->env[i], "###") && ft_strchr(ptr->env[i], '='))
			{
				ft_putstr_fd(ptr->env[i], STDOUT_FILENO);
				ft_putstr_fd("\n", STDOUT_FILENO);
			}
			i++;
		}
	}
	else
		return (ft_putstr_fd("minishelf: env: too many arguments\n", 2), 1);
	return (0);
}
