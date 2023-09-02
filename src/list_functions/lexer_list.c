/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:51 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/30 15:44:13 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_lexer	*new_node(char **str);
static void		add_new_node(t_lexer **root, t_lexer *new);

t_lexer	*lexer_list_init(char **str)
{
	int	i;
	t_lexer *root;
	t_lexer *node;

	i = 0;
	root = new_node(str + i);
	i += count_cmd(str + i);
	while(str[i++])
	{
		node = new_node(str + i);
		if (node == NULL)
			return (NULL);
		add_new_node(&root, node);
		i += count_cmd(str + i);
		
	}
	return (root);
}

char	**save_command_args(int cmd_count, char **input)
{
	char	**command_array;
	int		i;

	command_array = malloc(sizeof(char *) * (cmd_count + 1));
	if (!command_array)
		return (NULL);
	i = 0;
	while (i < cmd_count)
	{
		command_array[i] = ft_strdup(input[i]);
		if (command_array[i++] == NULL)
			return (NULL);
	}
	return (command_array);
}

static t_lexer	*new_node(char **input)
{
	int	i;
	int cmd_count; 
	t_lexer	*node;

	i = 0;
	cmd_count = count_cmd(input);
	node = malloc(sizeof(t_lexer));
	if (!node)
		return (NULL);

	node->cmd = save_command_args(cmd_count, input);
	i = cmd_count;
	node->cmd[cmd_count] = NULL;
	if (input[i] && check_token(input[i][0]))
	{
		node->token = ft_strdup(input[i]);
		if (node->token == NULL)
			return(NULL);
	}
	else
		node->token = NULL;
	node->next = NULL;
	return (node);
}

static void	add_new_node(t_lexer **root, t_lexer *new)
{
	t_lexer	*current;

	current = *root;
	while(current->next)
		current = current->next;
	current->next = new;
}
