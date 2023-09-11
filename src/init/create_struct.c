/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/03 16:23:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_god	*create_god_struct(char **envp)
{
	int		i;
	t_god	*god_struct;

	i = 0;
	while (envp[i])
		i++;
	god_struct = malloc(sizeof(t_god));
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
	increment_shell_level(god_struct->env);
	god_struct->env[i] = NULL;
	god_struct->parser_list = NULL;
	god_struct->heredoc_names = NULL;
	return (god_struct);
}
