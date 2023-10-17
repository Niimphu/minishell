/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:54:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/17 23:03:00 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <termios.h>

/* char	**init_env(char **original_env, int size); */
static char	**clone_env(char **original_env);
static int	count_env(char **original_env);

t_god	*create_god_struct(char **original_env)
{
	t_god	*god_struct;

	god_struct = malloc(sizeof(t_god));
	if (!god_struct)
		return (NULL);
	god_struct->og_termios = ft_calloc(1, sizeof(struct termios));
	if (!god_struct->og_termios)
		return (NULL);
	god_struct->env = clone_env(original_env);
	if (!god_struct->env)
		return (NULL);
	god_struct->parser_list = NULL;
	god_struct->exec_list = NULL;
	god_struct->blocks = 0;
	god_struct->exit_status = 0;
	increment_shell_level(god_struct, god_struct->env);
	return (god_struct);
}

static char	**clone_env(char **original_env)
{
	char	**env;
	int		i;

	env = ft_calloc(count_env(original_env) + 1, sizeof(char *));
	if (!env)
		return (NULL);
	i = 0;
	while (original_env[i])
	{
		env[i] = ft_strdup(original_env[i]);
		if (!env[i])
			perror("rip");
		i++;
	}
	env[i] = NULL;
	return (env);
}

static int	count_env(char **original_env)
{
	int	i;

	i = 0;
	while (original_env[i])
		i++;
	return (i);
}

/* char	**init_env(char **original_env, int size)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = ft_calloc(sizeof(char *), size);
	if (!new_env)
		return (NULL);
	while (original_env[i + j])
	{
		if (!ft_strncmp(original_env[i + j], "OLDPWD=", 6))
			j++;
		new_env[i] = ft_strdup(original_env[i + j]);
		if (!new_env[i])
			return (free_string_array(&new_env), NULL);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
} */
