/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:19:48 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/10 23:20:43 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	increment_shell_level(char **env)
{
	char	*level;
	char	*temp;
	int		shell_level;
	int		i;

	level = get_env_var("SHLVL=", env, TRIM);
	if (!level)
		return (1);
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
