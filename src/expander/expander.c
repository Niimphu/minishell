/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/17 22:38:01 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_var(char *var, t_envp *tools)
{
	int	i;

	i = 0;
	var = var + 1;
	while(tools->env[i])
	{
		if (!ft_strncmp(var, tools->env[i], ft_strlen(var)))
		{
			var = ft_strdup(tools->env[i] + (ft_strlen(var) + 1));
			if (!var)
				perror("Error setting variable");
		}
		i++;
	}
	return (var);
}

void	print_sorted_envp()
{
	printf("nothing to see here\n");
}

void	unset_build_in(t_envp *tools, char **cmd)
{
	int i;

	i = 0;
	while (tools->env[i] && ft_strncmp(cmd[1], tools->env[i], ft_strlen(cmd[1])))
		i++;
	printf("found %s\n", tools->env[i]);
	while(tools->env[i])
	{
		printf("switching %s with %s\n", tools->env[i], tools->env[i + 1]);
		if (tools->env[i + 1])
			tools->env[i] = ft_strdup(tools->env[i + 1]);
		i++;
	}
	tools->env[i - 1] = NULL;
	i = 0;
	while (tools->env[i])
		printf("new ENV = %s\n", tools->env[i++]);
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

void	export_build_in(t_envp *tools, char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[1])
		print_sorted_envp();
	if (check_cmd(cmd[1]))
	{
		while (tools->env[i])
			i++;
		tools->env[i] = ft_strdup(cmd[1]);
	}
	else
	{
		perror("Variable has no value or multiple =");
		exit (1);
	}
	i = 0;
	while (tools->env[i])
		printf("new ENV = %s\n", tools->env[i++]);
}

void	expander(t_lexer **root, t_envp *tools)
{
	int		i;
	t_lexer	*ptr;

	ptr = *root;
	while(ptr)
	{
		i = 0;
		while (ptr->cmd[i])
		{
			if (ptr->cmd[i][0] == '$' && ft_strlen(ptr->cmd[i]) > 1)
				ptr->cmd[i] = get_var(ptr->cmd[i], tools);
			if (!ft_strncmp(ptr->cmd[i], "export", 6 ))
				export_build_in(tools, ptr-> cmd);
			if (!ft_strncmp(ptr->cmd[i], "unset", 5))
				unset_build_in(tools, ptr-> cmd);
			i++;
		}
		ptr = ptr->next;
	}
}
