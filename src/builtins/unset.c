/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:06:05 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/19 15:13:15 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	unset_this_rn(char *cmd, t_god *god_struct);

int	unset(char **cmd, t_god *god_struct)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	if (!cmd[i])
		return (0);
	while (cmd[i])
	{
		if (unset_this_rn(cmd[i], god_struct))
			error = 1;
		i++;
	}
	return (error);
}

static int	unset_this_rn(char *cmd, t_god *god_struct)
{
	int	i;

	i = 0;
	if (!verify_identifier("unset", cmd))
		return (FAIL);
	while (god_struct->env[i] && ft_strncmp(cmd, god_struct->env[i],
			first_index_of(god_struct->env[i], '=')))
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
