/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:06:05 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/16 15:04:56 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	unset(char **cmd, t_god *god_struct)
{
	int	i;
	
	i = 1;
	if (!cmd[i])
		return (1);
	if (!verify_identifier("unset", cmd[i]))
		return (1);
	while (god_struct->env[i] && ft_strncmp(cmd[1], god_struct->env[i]
			, first_index_of(god_struct->env[i], '=')))
		i++;
	if (!god_struct->env[i])
		return (0);
	free_string(&god_struct->env[i]);
	while (god_struct->env[i + 1])
	{
		if (god_struct->env[i + 1])
			god_struct->env[i] = god_struct->env[i + 1];
		i++;
	}
	god_struct->env[i] = NULL;
	return (0);
}
