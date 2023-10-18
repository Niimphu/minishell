/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:39:16 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/18 14:18:05 by Kekuhne          ###   ########.fr       */
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
			if (!ft_strcmp(ptr->env[i], "###") || !ft_strchr(ptr->env[i], '='))
				i++;
			else
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
