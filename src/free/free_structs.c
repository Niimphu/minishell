/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:41:11 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/28 12:45:50 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_god_struct(t_god **ptr)
{
	t_god	*god_struct;

	god_struct = *(ptr);
	free_string_array(&god_struct->env);
	free(god_struct->og_termios);
	ft_lstclear(&god_struct->parser_list, free_parser_node);
	ft_lstclear(&god_struct->exec_list, free_exec_node);
	free(god_struct);
	god_struct = NULL;
	*ptr = NULL;
}

void	free_lexer_node(void *node)
{
	t_lexer	*lexer_node;

	lexer_node = (t_lexer *)node;
	free_string(&lexer_node->string);
	free(node);
	node = NULL;
}

void	free_parser_node(void *node)
{
	t_parser	*parser_node;

	parser_node = (t_parser *)node;
	free_string_array(&parser_node->cmd_array);
	ft_lstclear(&(parser_node->files), free_file_node);
	free(node);
	node = NULL;
}

void	free_file_node(void *node)
{
	t_file	*file_node;

	file_node = (t_file *)node;
	if (file_node->operator == HEREDOC)
	{
		free_string(&file_node->delimiter);
		unlink(file_node->filename);
	}
	file_node->fd = close_fd(file_node->fd);
	free_string(&file_node->filename);
	free(node);
	node = NULL;
}

void	free_exec_node(void *node)
{
	t_exec	*exec_node;

	exec_node = (t_exec *)node;
	free_string(&exec_node->path);
	free(node);
	node = NULL;
}
