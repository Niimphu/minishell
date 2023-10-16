/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:24:56 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/16 15:09:48 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	cd_home(t_god *god_struct);
static int	update_pwd(t_god *god_struct);
static int	update_old_pwd(t_god *god_struct, char *old_dir);

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
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putstr_fd(" :No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

void	cd_home(t_god *god_struct)
{
	char	*home_directory;
	char	*old_directory;

	old_directory = getcwd(NULL, 1024);
	home_directory = get_var(ft_strdup("HOME"), god_struct);
	if (!home_directory || !old_directory || chdir(home_directory) == -1
		|| update_pwd(god_struct) || update_old_pwd(god_struct, old_directory))
		perror("cd");
	free_string(&home_directory);
}

static int	update_pwd(t_god *god_struct)
{
	int		i;
	char	*directory;
	char	*temp;

	i = 0;
	directory = getcwd(NULL, 1024);
	if (!directory)
		return (perror("cd"), 1);
	temp = ft_strjoin("PWD=", directory);
	free_string(&directory);
	directory = temp;
	if (!directory)
		return (1);
	while (god_struct->env[i])
	{
		if (!ft_strncmp(god_struct->env[i], "PWD=", 4))
		{
			free_string(&god_struct->env[i]);
			god_struct->env[i] = directory;
		}
		i++;
	}
	return (0);
}

static int	update_old_pwd(t_god *god_struct, char *old_directory)
{
	char	*directory;
	int		i;

	i = 0;
	directory = ft_strjoin("OLDPWD=", old_directory);
	if (!directory)
		return (1);
	free_string(&old_directory);
	while (god_struct->env[i])
	{
		if (!ft_strncmp(god_struct->env[i], "OLDPWD=", 7))
		{
			free_string(&god_struct->env[i]);
			god_struct->env[i] = directory;
		}
		i++;
	}
	return (0);
}
