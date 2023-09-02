/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_build_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:24:56 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/30 17:19:34 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//bug cd should take you home

static int	update_old_pwd(t_envp *tools, char *dir)
{
	int	i;

	i = 0;
	dir = ft_strjoin("OLDPWD=", dir);
	if (!dir)
		return (1);
	while (tools->env[i])
	{
		if (!strncmp(tools->env[i], "OLDPWD=", 7))
		{
			tools->env[i] = ft_strdup(dir);
			break ;
		}
		i++;
	}
	free(dir);
	return (0);
}

static int	update_pwd(t_envp *tools)
{
	int		i;
	char	*dir;

	i = 0;
	dir = getcwd(NULL, 1024);
	if (!dir)
	{
		perror("cd");
		return (1);
	}
	dir = ft_strjoin("PWD=", dir);
	if (!dir)
		return (1);
	while (tools->env[i])
	{
		if (!strncmp(tools->env[i], "PWD=", 4))
		{
			tools->env[i] = ft_strdup(dir);
			break ;
		}
		i++;
	}
	free(dir);
	return (0);
}

int	cd_build_in(char *dir, t_envp *tool)
{
	char	*old_dir;

	old_dir = getcwd(NULL, 1024);
	if (!old_dir || update_old_pwd(tool, old_dir))
	{
		perror("cd");
		return (1);
	}
	if (chdir(dir) == -1 || update_pwd(tool))
	{
		perror("cd");
		return (1);
	}
	free(old_dir);
	return (0);
}
