/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/30 16:36:25 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
				export_build_in(tools, ptr->cmd);
			if (!ft_strncmp(ptr->cmd[i], "unset", 5))
				unset_build_in(tools, ptr->cmd);
			if (!ft_strncmp(ptr->cmd[i], "cd", 2))
				cd_build_in(ptr->cmd[1], tools);
			if (!ft_strncmp(ptr->cmd[i], "pwd", 3))
				pwd_build_in(tools);
			if (!ft_strncmp(ptr->cmd[i], "env", 3))
				env_build_in(tools);
			if (!ft_strncmp(ptr->cmd[i], "echo", 3))
				echo_build_in(ptr->cmd, tools);
			i++;
		}
		ptr = ptr->next;
	}
}
