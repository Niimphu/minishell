/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:51:18 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/03 16:48:16 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_env_var(char *var, char **env, int trim)
{
	int	i;

	i = 0;
	if (trim)
		trim = (int)ft_strlen(var);
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, trim))
			return (env[i] + trim);
		i++;
	}
	return (NULL);
}

char	*get_var(char *var, t_god *god_struct)
{
	int		i;
	char	*new_var;
	char	*tmp;

	i = 0;
	if (!var)
		return ("\n");
	new_var = ft_strtrim(var, "\"\'$");
	while (god_struct->env[i])
	{
		if (!ft_strncmp(new_var, god_struct->env[i],
				first_index_of(god_struct->env[i], '=')))
		{
			tmp = ft_strdup(god_struct->env[i] + (ft_strlen(new_var) + 1));
			if (!tmp)
				return (free(new_var), NULL);
			free_string(&new_var);
			new_var = tmp;
			break ;
		}
		i++;
	}
	if (!god_struct->env[i])
		return (free_string(&new_var), free_string(&var), NULL);
	return (free_string(&var), new_var);
}

int	verify_identifier(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[0] != '_' && !ft_isalpha(cmd[0]))
	{
		ft_putstr_fd("unset: `", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("': is not a valid identifier\n", 2);
		return (0);
	}
	while (cmd[i++])
	{
		if (cmd[i] && (!ft_isalnum(cmd[i]) && cmd[i] != '_'))
		{
			ft_putstr_fd("unset: `", 2);
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd("': is not a valid identifier\n", 2);
			return (0);
		}
	}
	return (1);
}
