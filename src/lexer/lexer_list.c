/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:51 by yiwong            #+#    #+#             */
/*   Updated: 2023/08/28 13:39:09 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_lexer	*new_lexer_node(char **array);
static t_lexer	*fill_node(t_lexer *node, char **array);

t_list	*create_lexer_list(char **split_string)
{
	t_list	*lexer_list;
	t_lexer	*new_node;
	char	*array_start;

	array_start = *split_string;
	new_node = new_lexer_node(split_string);
	lexer_list = ft_lstnew(new_node);
	split_string += count_cmd(split_string);
	while (*split_string)
	{
		new_node = new_lexer_node(split_string);
		ft_lstadd_back(&lexer_list, ft_lstnew(new_node));
		split_string += count_cmd(split_string);
	}
	free(array_start);
	return (lexer_list);
}

static t_lexer	*new_lexer_node(char **array)
{
	t_lexer	*lexer_node;

	lexer_node = ft_calloc(1, sizeof(t_lexer));
	if (!lexer_node)
		return (NULL);
	lexer_node->cmd = NULL;
	lexer_node->operator = NULL;
	fill_node(lexer_node, array);
	return (lexer_node);
}

static t_lexer	*fill_node(t_lexer *node, char **array)
{
	int		i;
	int		cmd_count;

	i = 0;
	cmd_count = count_cmd(array);
	node->cmd = ft_calloc(cmd_count + 1, sizeof(char *));
	if (!node->cmd)
		return (NULL);
	while (i < cmd_count)
	{
		node->cmd[i] = ft_strdup(array[i]);
		i++;
	}
	node->cmd[i] = NULL;
	if (array[i])
		node->operator = ft_strdup(array[i]);
	return (node);
}
//
//
//static t_lexer	*new_node(char **str);
//static void		add_new_node(t_lexer **root, t_lexer *new);
//
//t_lexer	*lexer_list_init(char **str)
//{
//	int		i;
//	t_lexer	*root;
//	t_lexer	*node;
//
//	i = 0;
//	root = new_node(str + i);
//	i += count_cmd(str + i);
//	while (str[i++])
//	{
//		node = new_node(str + i);
//		if (node == NULL)
//			return (NULL);
//		add_new_node(&root, node);
//		i += count_cmd(str + i);
//	}
//	return (root);
//}
//
//char	**save_command_args(int cmd_count, char **input)
//{
//	char	**command_array;
//	int		i;
//
//	command_array = malloc(sizeof(char *) * cmd_count + 1);
//	if (!command_array)
//		return (NULL);
//	i = 0;
//	while (i < cmd_count)
//	{
//		command_array[i] = ft_strdup(input[i]);
//		if (command_array[i++] == NULL)
//			return (NULL);
//	}
//	return (command_array);
//}
//
//static t_lexer	*new_node(char **input)
//{
//	int	i;
//	int cmd_count;
//	t_lexer	*node;
//
//	i = 0;
//	cmd_count = count_cmd(input);
//	node = malloc(sizeof(t_lexer));
//	if (!node)
//		return (NULL);
//
//	node->cmd = save_command_args(cmd_count, input);
//	i = count_cmd(node->cmd);
//	node->cmd[cmd_count] = NULL;
//	if (input[i] && contains_operator(input[i][0]))
//	{
//		node->operator = ft_strdup(input[i]);
//		if (node->operator == NULL)
//			return(NULL);
//	}
//	else
//		node->operator = NULL;
//	node->next = NULL;
//	return (node);
//}
//
//static void	add_new_node(t_lexer **root, t_lexer *new)
//{
//	t_lexer	*current;
//
//	current = *root;
//	while(current->next)
//		current = current->next;
//	current->next = new;
//}
