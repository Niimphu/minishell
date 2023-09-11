/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/11 14:23:26 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	expander(t_list **root, t_god *god_struct)
{
	int			i;
	t_list		*ptr;
	t_parser	*node;

	ptr = *root;
	while (ptr)
	{
		i = 0;
		node = (t_parser *)ptr->content;
		if (!node->cmd)
			return ;
		while (node->cmd[i])
		{
			if (node->cmd[i][0] == '$' && ft_strlen(node->cmd[i]) > 1)
				node->cmd[i] = get_var(node->cmd[i], god_struct);
			if (!ft_strncmp(node->cmd[i], "export", 6))
				export(god_struct, node->cmd);
			if (!ft_strncmp(node->cmd[i], "unset", 5))
				unset(god_struct, node->cmd);
			if (!ft_strncmp(node->cmd[i], "cd", 2))
				cd(node->cmd[1], god_struct);
			if (!ft_strncmp(node->cmd[i], "pwd", 3))
				pwd(god_struct);
			if (!ft_strncmp(node->cmd[i], "env", 3))
				env(god_struct);
			if (!ft_strncmp(node->cmd[i], "echo", 4))
				echo(node->cmd, god_struct);
			if (!ft_strncmp(node->cmd[i], "exit", 4))
				exit_minishell(god_struct);
			i++;
		}
		ptr = ptr->next;
	}
}
