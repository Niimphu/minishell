/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:24:56 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/03 16:23:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//kinda ghetto pls fix

static int	update_old_pwd(t_god *god_struct, char *dir)
{
	int	i;

	i = 0;
	dir = ft_strjoin("OLDPWD=", dir);
	if (!dir)
		return (1);
	while (god_struct->env[i])
	{
		if (!strncmp(god_struct->env[i], "OLDPWD=", 7))
		{
			god_struct->env[i] = ft_strdup(dir);
			break ;
		}
		i++;
	}
	free(dir);
	return (0);
}

static int	update_pwd(t_god *god_struct)
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
	while (god_struct->env[i])
	{
		if (!strncmp(god_struct->env[i], "PWD=", 4))
		{
			god_struct->env[i] = ft_strdup(dir);
			break ;
		}
		i++;
	}
	free(dir);
	return (0);
}

int	cd(char *dir, t_god *god_struct)
{
	char	*old_dir;
	bool	free_dir;
	int		return_value;

	old_dir = getcwd(NULL, 1024);
	free_dir = false;
	return_value = 0;
	if (!dir)
	{
		dir = get_var(ft_strdup("$HOME"), god_struct);
		free_dir = true;
	}
	if (!old_dir || update_old_pwd(god_struct, old_dir)
		|| chdir(dir) == -1 || update_pwd(god_struct))
	{
		perror(ft_strcat("cd: ", dir));
		return_value = 1;
	}
	free(old_dir);
	if (free_dir)
		free_string(&dir);
	return (return_value);
}
