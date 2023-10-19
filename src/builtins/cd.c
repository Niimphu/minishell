/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:24:56 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/19 16:36:23 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

#define STOOPID "minishelf: error retrieving current directory: getcwd: \
	cannot access parent directories: No such file or directory\n"

static int	cd_home(t_god *god_struct);
static int	update_pwd(t_god *god_struct, char *old_dir);
static int	update_old_pwd(t_god *god_struct, char *old_dir);
static void	set_new_oldpwd(t_god *god_struct, char *dir);

int	cd(char *dir, t_god *god_struct)
{
	char	*old_dir;

	if (!dir)
		return (cd_home(god_struct));
	old_dir = getcwd(NULL, 1024);
	if (!old_dir && (!ft_strncmp(".", dir, 2) || !ft_strncmp("./", dir, 2)))
		return (ft_putstr_fd(STOOPID, 2), 1);
	if (!get_env_var("PWD=", god_struct->env, 0))
	{
		chdir(dir);
		update_old_pwd(god_struct, old_dir);
		return (0);
	}
	if (!old_dir)
		old_dir = ft_strdup(get_env_var("PWD=", god_struct->env, 1));
	if (!old_dir || chdir(dir) == -1 || update_pwd(god_struct, old_dir))
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (free_string(&old_dir), 1);
	}
	return (0);
}

static int	cd_home(t_god *god_struct)
{
	char	*home_dir;
	char	*old_dir;

	home_dir = get_var(ft_strdup("HOME"), god_struct);
	if (!ft_strlen(home_dir))
		return (ft_putstr_fd("minishelf: cd: HOME not set\n", 2),
			free_string(&home_dir), 1);
	if (chdir(home_dir) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(home_dir, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (free_string(&home_dir), 1);
	}
	old_dir = getcwd(NULL, 1024);
	if (!old_dir)
		old_dir = ft_strdup(get_env_var("PWD=", god_struct->env, 1));
	if (old_dir)
		update_pwd(god_struct, old_dir);
	free_string(&home_dir);
	return (0);
}

static int	update_pwd(t_god *god_struct, char *old_dir)
{
	int		i;
	char	*dir;
	char	*temp;

	i = 0;
	dir = getcwd(NULL, 1024);
	if (!dir)
		return (1);
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
	new_env = ft_calloc(sizeof(char *), new_split_size(god_struct->env) + 2);
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
