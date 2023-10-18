/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:24:56 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/18 14:14:32 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void		cd_home(t_god *god_struct);
static int	update_pwd(t_god *god_struct, char *old_dir);
static int	update_old_pwd(t_god *god_struct, char *old_dir);
static void	set_new_oldpwd(t_god *god_struct, char *dir);

int	cd(char *dir, t_god *god_struct)
{
	char	*old_dir;

	if (!dir)
	{
		cd_home(god_struct);
		return (1);
	}
	if (!get_env_var("PWD=", god_struct->env, 0))
	{
		chdir(dir);
		update_old_pwd(god_struct, getcwd(NULL, 1024));
		return (0);
	}
	old_dir = getcwd(NULL, 1024);
	if (!old_dir || chdir(dir) == -1 || update_pwd(god_struct, old_dir))
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

void	cd_home(t_god *god_struct)
{
	char	*home_dir;
	char	*old_dir;

	old_dir = getcwd(NULL, 1024);
	home_dir = get_var(ft_strdup("HOME"), god_struct);
	if (!home_dir || !old_dir || chdir(home_dir) == -1
		|| update_pwd(god_struct, old_dir))
		perror("cd");
	free_string(&home_dir);
}

static int	update_pwd(t_god *god_struct, char *old_dir)
{
	int		i;
	char	*dir;
	char	*temp;

	i = 0;
	dir = getcwd(NULL, 1024);
	if (!dir)
		return (perror("cd"), 1);
	temp = ft_strjoin("PWD=", dir);
	free_string(&dir);
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
	update_old_pwd(god_struct, old_dir);
	return (0);
}

static int	update_old_pwd(t_god *god_struct, char *old_dir)
{
	int		i;
	int		found;
	char	*dir;

	i = 0;
	found = 0;
	dir = ft_strjoin("OLDPWD=", old_dir);
	if (!dir)
		return (1);
	free_string(&old_dir);
	while (god_struct->env[i])
	{
		if (!ft_strncmp(god_struct->env[i], "OLDPWD=", 7))
			found = i;
		i++;
	}
	if (found != 0)
	{
		free_string(&god_struct->env[found]);
		god_struct->env[found] = dir;
	}
	else
		set_new_oldpwd(god_struct, dir);
	return (0);
}

static void	set_new_oldpwd(t_god *god_struct, char *dir)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = ft_calloc(sizeof(char *), new_split_size(god_struct->env); + 2);
	if (!new_env)
		return ;
	while (god_struct->env[i])
	{
		if (!ft_strncmp(god_struct->env[i], "PWD=", 4))
		{
			new_env[j++] = ft_strdup(god_struct->env[i++]);
			new_env[j++] = dir;
		}
		else
			new_env[j++] = ft_strdup(god_struct->env[i++]);
	}
	if (j == i)
		new_env[j++] = dir;
	new_env[j] = NULL;
	free_string_array(&god_struct->env);
	god_struct->env = new_env;
}
