/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/03 16:24:09 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	expander(t_list **root, t_god *tools)
{
	int		i;
	t_list	*ptr;
	t_parser	*node;

	ptr = *root;
	while (ptr)
	{
		i = 0;
		node = (t_parser *)ptr->content;
		while (node->cmd[i])
		{
			if (node->cmd[i][0] == '$' && ft_strlen(node->cmd[i]) > 1)
				node->cmd[i] = get_var(node->cmd[i], tools);
			if (!ft_strncmp(node->cmd[i], "export", 6 ))
				export(tools, node->cmd);
			if (!ft_strncmp(node->cmd[i], "unset", 5))
				unset(tools, node->cmd);
			if (!ft_strncmp(node->cmd[i], "cd", 2))
				cd(node->cmd[1], tools);
			if (!ft_strncmp(node->cmd[i], "pwd", 3))
				pwd(tools);
			if (!ft_strncmp(node->cmd[i], "env", 3))
				env(tools);
			if (!ft_strncmp(node->cmd[i], "echo", 3))
				echo(node->cmd, tools);
			i++;
		}
		ptr = ptr->next;
	}
}
