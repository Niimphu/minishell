/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/22 17:18:41 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_envp	*create_god_struct(char **envp)
{
	int		i;
	t_envp	*god_struct;

	i = 0;
	god_struct = malloc(sizeof(t_envp));
	if (!god_struct)
		return (NULL);
	god_struct->env = malloc(sizeof(char *));
	while (envp[i])
	{
		god_struct->env[i] = malloc(sizeof(char) * ft_strlen(envp[i]));
		if (!god_struct->env[i])
			perror("upsi no envp!");
		god_struct->env[i] = envp[i];
		i++;
	}
	god_struct->lexer_list = NULL;
	return (god_struct);
}
