/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/24 20:23:14 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_envp	*create_god_struct(char **envp)
{
	int		i;
	t_envp	*god_struct;

	i = 0;
	god_struct = ft_calloc(1, sizeof(t_envp));
	if (!god_struct)
		return (NULL);
	god_struct->env = ft_calloc(count_cmd(envp) + 1, sizeof(char *));
	if (!god_struct->env)
		return (NULL);
	while (envp[i])
	{
		god_struct->env[i] = ft_strdup(envp[i]);
		if (!god_struct->env[i])
			perror("upsi no envp!");
		i++;
	}
	god_struct->lexer_list = NULL;
	return (god_struct);
}
