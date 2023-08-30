/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/29 20:29:19 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_envp	*create_god_struct(char **envp)
{
	int		i;
	t_envp	*god_struct;

	i = 0;
	while (envp[i])
		i++;
	god_struct = malloc(sizeof(t_envp));
	if (!god_struct)
		return (NULL);
	god_struct->env = malloc(sizeof(char *) * (i + 1));
	if (!god_struct->env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		god_struct->env[i] = ft_strdup(envp[i]);
		if (!god_struct->env[i])
			perror("upsi no envp!");
		i++;
	}
	god_struct->env[i] = NULL;
	god_struct->lexer_struct = NULL;
	return (god_struct);
}
