/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:32:33 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/03 16:23:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	env(int fd_out, t_god *god_struct)
{
	int		i;
	t_god	*ptr;

	i = 0;
	if (!god_struct->env)
		return (1);
	ptr = god_struct;
	while (ptr->env[i])
	{
		ft_putstr_fd(ptr->env[i++], fd_out);
		ft_putstr_fd("\n", fd_out);
	}
	return (0);
}

static void	print_sorted_envp(int fd_out, t_god *god_struct)
{
	int		i;
	int		j;
	t_god	*ptr;

	i = 0;
	ptr = god_struct;
	while (i <= 255)
	{
		j = -1;
		while (ptr->env[++j])
		{
			if (i == ptr->env[j][0])
			{
				ft_putstr_fd(ptr->env[j], fd_out);
				ft_putstr_fd("\n", fd_out);
			}
		}
		i++;
	}
}

static char	**new_env(t_god *god_struct, char *cmd)
{
	int		i;
	char	**new_env;

	i = 0;
	while (god_struct->env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (NULL);
	i = 0;
	while (god_struct->env[i])
	{
		new_env[i] = ft_strdup(god_struct->env[i]);
		if (!new_env[i])
			return (NULL);
		i++;
	}
	new_env[i] = ft_strdup(cmd);
	if (!new_env[i])
		return (NULL);
	free_string_array(&god_struct->env);
	new_env[++i] = NULL;
	return (new_env);
}

int	export(char **cmd, int fd_out, t_god *god_struct)
{
	if (!cmd[1])
	{
		print_sorted_envp(fd_out, god_struct);
		return (0);
	}
	god_struct->env = new_env(god_struct, cmd[1]);
	if (!god_struct->env)
		return (1);
	return (0);
}
