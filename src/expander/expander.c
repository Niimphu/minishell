/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/25 19:42:58 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_var(char *var, t_envp *god_struct)
{
	int	i;

	i = 0;
	var = var + 1;
	while (god_struct->env[i])
	{
		if (!ft_strncmp(var, god_struct->env[i], ft_strlen(var)))
		{
			var = ft_strdup(god_struct->env[i] + (ft_strlen(var) + 1));
			if (!var)
				perror("Error setting variable");
		}
		i++;
	}
	return (var);
}

void	print_sorted_envp(void)
{
	printf("nothing to see here\n");
}

void	unset_build_in(t_envp *god_struct, char **cmd)
{
	int	i;

	i = 0;
	while (god_struct->env[i] && ft_strncmp(cmd[1],
			god_struct->env[i], ft_strlen(cmd[1])))
		i++;
	printf("found %s\n", god_struct->env[i]);
	while (god_struct->env[i])
	{
		printf("switching %s with %s\n", god_struct->env[i], god_struct->env[i + 1]);
		if (god_struct->env[i + 1])
			god_struct->env[i] = ft_strdup(god_struct->env[i + 1]);
		i++;
	}
	god_struct->env[i - 1] = NULL;
	i = 0;
	while (god_struct->env[i])
		printf("new ENV = %s\n", god_struct->env[i++]);
}

int	check_cmd(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	printf("checking %s\n", str);
	while (str[i])
	{
		if (str[i++] == '=')
		{
			if ((str[i] == '\0' || str[i] == '='))
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void	export_build_in(t_envp *god_struct, char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[1])
		print_sorted_envp();
	if (check_cmd(cmd[1]))
	{
		while (god_struct->env[i])
			i++;
		god_struct->env[i] = ft_strdup(cmd[1]);
	}
	else
	{
		perror("Variable has no value or multiple =");
		exit (1);
	}
	i = 0;
	while (god_struct->env[i])
		printf("new ENV = %s\n", god_struct->env[i++]);
}

void	expander(t_lexer **root, t_envp *god_struct)
{
	int		i;
	t_lexer	*ptr;

	ptr = *root;
	while (ptr)
	{
		i = 0;
		while (ptr->cmd[i])
		{
			if (ptr->cmd[i][0] == '$' && ft_strlen(ptr->cmd[i]) > 1)
				ptr->cmd[i] = get_var(ptr->cmd[i], god_struct);
			if (!ft_strncmp(ptr->cmd[i], "export", 6))
				export_build_in(god_struct, ptr-> cmd);
			if (!ft_strncmp(ptr->cmd[i], "unset", 5))
				unset_build_in(god_struct, ptr-> cmd);
			i++;
		}
		ptr = ptr->next;
	}
}
