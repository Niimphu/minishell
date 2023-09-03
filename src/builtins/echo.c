/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:28:22 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/03 16:23:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_var(char *var, t_god *tools)
{
	int		i;
	char	*new_var;

	i = 0;
	
	if (!var)
		return ("\n");
	new_var = ft_strtrim(var, "\"\'$");
	free(var);
	while (tools->env[i])
	{
		if (!ft_strncmp(new_var, tools->env[i], ft_strlen(new_var)))
		{
			new_var = ft_strdup(tools->env[i] + (ft_strlen(new_var) + 1));
			if (!new_var)
				return (NULL);
		}
		i++;
	}
	return (new_var);
}

int	echo(char **cmd, t_god *tools)
{
	int	i;
	int	new_line_flag;

	i = 1;
	new_line_flag = 0;
	while (cmd[i] && !ft_strncmp(cmd[i], "-n", ft_strlen(cmd[i])))
	{
		new_line_flag = 1;
		i++;
	}
	while (cmd[i])
	{
		if (ft_strchr(cmd[i], '$') && !ft_strchr(cmd[i], '\'')
			&& ft_strlen(cmd[i]) > 1)
		{
			cmd[i] = get_var(cmd[i], tools);
			if (!cmd[i])
				return (1);
		}
		else
			cmd[i] = ft_strtrim(cmd[i], "\"\'");
		printf("%s ", cmd[i++]);
	}
	if (new_line_flag == 0 || !cmd[1])
		printf("\n");
	return (0);
}
