/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_build_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:35:44 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/30 17:25:49 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	unset_build_in(t_envp *tools, char **cmd)
{
	int	i;

	i = 0;
	if (!cmd[1])
		return (1);
	while (tools->env[i] && ft_strncmp(cmd[1], tools->env[i]
			, ft_strlen(cmd[1])))
		i++;
	while (tools->env[i])
	{
		if (tools->env[i + 1])
			tools->env[i] = ft_strdup(tools->env[i + 1]);
		i++;
	}
	tools->env[i - 1] = NULL;
	return (0);
}
