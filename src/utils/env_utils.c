/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:51:18 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/06 14:51:36 by yiwong           ###   ########.fr       */
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
