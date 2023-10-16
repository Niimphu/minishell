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
#include <termios.h>

static char	**clone_env(char **original_env);
static int	count_env(char **original_env);

t_god	*create_god_struct(char **original_env)
{
	t_god	*god_struct;

	god_struct = malloc(sizeof(t_god));
	if (!god_struct)
		return (NULL);
	god_struct->env = clone_env(original_env);
	god_struct->og_termios = ft_calloc(1, sizeof(struct termios));
	if (!god_struct->env || !god_struct->og_termios)
		return (NULL);
	increment_shell_level(god_struct->env);
	god_struct->parser_list = NULL;
	god_struct->blocks = 0;
	god_struct->exit_status = 0;
	return (god_struct);
}

static char	**clone_env(char **original_env)
{
	char	**env;
	int		i;

	env = ft_calloc(count_env(original_env) + 1, sizeof(char *));
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
