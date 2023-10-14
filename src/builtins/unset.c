/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:06:05 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/14 17:42:56 by Kekuhne          ###   ########.fr       */
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

int	unset(char **cmd, t_god *god_struct)
{
	int	i;

	i = 0;
	if (!cmd[1])
		return (1);
	if (!verify_identifier("unset", cmd[1]))
		return (1);
	while (god_struct->env[i] && ft_strncmp(cmd[1], god_struct->env[i]
			, ft_strlen(cmd[1])))
		i++;
	while (god_struct->env[i])
	{
		if (god_struct->env[i + 1])
			god_struct->env[i] = ft_strdup(god_struct->env[i + 1]);
		i++;
	}
	free_string(&god_struct->env[i - 1]);
	return (0);
}
