/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:24:56 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/03 15:10:33 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	update_old_pwd(t_god *god_struct, char *old_dir)
{
	char	*dir;
	int		i;

	i = 0;
	dir = ft_strjoin("OLDPWD=", old_dir);
	if (!dir)
		return (1);
	free_string(&old_dir);
	while (god_struct->env[i])
	{
		if (!ft_strncmp(god_struct->env[i], "OLDPWD=", 7))
		{
			free_string(&god_struct->env[i]);
			god_struct->env[i] = dir;
		}
		i++;
	}
	return (0);
}

static int	update_pwd(t_god *god_struct)
{
	int		i;
	char	*dir;
	char	*temp;

	i = 0;
	dir = getcwd(NULL, 1024);
	if (!dir)
		return (perror("cd"), 1);
	temp = ft_strjoin("PWD=", dir);
	free(dir);
	dir = temp;
	if (!dir)
		return (1);
	while (god_struct->env[i])
	{
		if (!ft_strncmp(god_struct->env[i], "PWD=", 4))
		{
			free_string(&god_struct->env[i]);
			god_struct->env[i] = dir;
		}
		i++;
	}
	return (0);
}

void	cd_home(t_god *god_struct)
{
	char	*home_dir;
	char	*old_dir;

	old_dir = getcwd(NULL, 1024);
	home_dir = get_var(ft_strdup("$HOME"), god_struct);
	if (!home_dir || !old_dir || chdir(home_dir) == -1
		|| update_pwd(god_struct) || update_old_pwd(god_struct, old_dir))
	{
		if (home_dir)
			free(home_dir);
		perror("cd");
	}
	else
		free(home_dir);
}

int	cd(char *dir, t_god *god_struct)
{
	char	*old_dir;

	if (!dir)
	{
		cd_home(god_struct);
		return (1);
	}
	old_dir = getcwd(NULL, 1024);
	if (!old_dir || update_old_pwd(god_struct, old_dir)
		|| chdir(dir) == -1 || update_pwd(god_struct))
	{
		perror("cd");
		return (1);
	}
	return (0);
}
