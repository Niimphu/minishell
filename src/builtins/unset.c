/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:06:05 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/09 16:58:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:35:44 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/03 16:23:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	unset(t_god *tools, char **cmd)
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
	free_string(&tools->env[i - 1]);
	return (0);
}
