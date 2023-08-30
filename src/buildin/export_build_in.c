/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_build_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:32:33 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/30 16:38:07 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	env_build_in(t_envp *tools)
{
	int		i;
	t_envp	*ptr;

	i = 0;
	ptr = tools;
	while (ptr->env[i])
		printf("%s\n", ptr->env[i++]);
	return (0);
}

static void	print_sorted_envp(t_envp *tools)
{
	int		i;
	int		j;
	t_envp	*ptr;

	i = 0;
	ptr = tools;
	while (i <= 255)
	{
		j = -1;
		while (ptr->env[++j])
			if (i == ptr->env[j][0])
				printf("%s\n", ptr->env[j]);
		i++;
	}
}

static char	**new_env(t_envp *tools, char *cmd)
{
	int		i;
	char	**new_env;

	i = 0;
	while (tools->env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (NULL);
	i = 0;
	while (tools->env[i])
	{
		new_env[i] = ft_strdup(tools->env[i]);
		if (!new_env[i])
			return (NULL);
		free(tools->env[i]);
		i++;
	}
	new_env[i] = ft_strdup(cmd);
	if (!new_env[i])
		return (NULL);
	free(tools->env);
	new_env[++i] = NULL;
	return (new_env);
}

int	export_build_in(t_envp *tools, char **cmd)
{
	int		i;

	i = 0;
	if (!cmd[1])
	{
		print_sorted_envp(tools);
		return (0);
	}
	tools->env = new_env(tools, cmd[1]);
	if (!tools->env)
		return (1);
	return (0);
}
