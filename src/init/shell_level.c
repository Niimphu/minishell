/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:19:48 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/17 15:55:10 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	new_shell_lvl(t_god *god_struct)
{
	int		i;
	char	*tmp;
	i = 0;
	while (god_struct->env[i])
	{
		if (!ft_strncmp(god_struct->env[i], "PWD=", 4))
			break ;
		i++;
	}
	tmp = god_struct->env[i];
	god_struct->env[i++] = ft_strdup("SHLVL=1");
	free_string(&god_struct->env[i]);
	god_struct->env[i] = tmp;
}

int	increment_shell_level(t_god *god_struct, char **env)
{
	char	*level;
	char	*temp;
	int		shell_level;
	int		i;

	level = get_env_var("SHLVL=", env, TRIM);
	if (!level)
	{
		new_shell_lvl(god_struct);
		return (0);
	}
	shell_level = ft_atoi(level) + 1;
	i = 0;
	while (ft_strncmp("SHLVL=", env[i], 6))
		i++;
	if (!env[i])
		return (-1);
	free(env[i]);
	temp = ft_itoa(shell_level);
	env[i] = ft_strjoin("SHLVL=", temp);
	free_string(&temp);
	return (0);
}
