/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/17 19:51:26 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <termios.h>

char	**init_env(char **envp , int size)
{
	int		i;
	int		j;
	char	**new_env;
	
	i = 0;
	j = 0;
	new_env = malloc(sizeof(char *) * size);
	if (!new_env)
		return (NULL);
	while (envp[i + j])
	{
		if (!ft_strncmp(envp[i + j], "OLDPWD=", 6))
			j++;
		new_env[i] = ft_strdup(envp[i + j]);
		if (!new_env[i])
			return (free_string_array(&new_env), NULL);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

t_god	*create_god_struct(char **envp)
{
	int		i;
	t_god	*god_struct;

	i = new_split_size(envp);
	god_struct = malloc(sizeof(t_god));
	if (!god_struct)
		return (NULL);
	god_struct->og_termios = ft_calloc(1, sizeof(struct termios));
	if (!god_struct->og_termios)
		return (NULL);
	god_struct->env = init_env(envp, i);
	if (!god_struct->env)
		return (NULL);
	god_struct->parser_list = NULL;
	god_struct->exit_status = 0;
	increment_shell_level(god_struct, god_struct->env);
	return (god_struct);
}
