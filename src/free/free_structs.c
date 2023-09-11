/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:41:11 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/08 15:51:12 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
	free_string_array(&parser_node->cmd);
	close_fd(&parser_node->fd);
	free(node);
	node = NULL;
}

void	free_file_node(void *node)
{
	t_file	*file_node;

	file_node = (t_file *)node;
	if (file_node->temp)
		unlink(file_node->filename);
	free_string(&file_node->filename);
	free(node);
	node = NULL;
}

void	free_god_struct(t_god **ptr)
{
	t_god	*god_struct;

	god_struct = *(ptr);
	free_string_array(&god_struct->env);
	ft_lstclear(&god_struct->parser_list, free_parser_node);
	ft_lstclear(&god_struct->heredoc_names, free_file_node);
	free(god_struct);
	god_struct = NULL;
	*ptr = NULL;
}
