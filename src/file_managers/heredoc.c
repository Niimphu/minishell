/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:33:56 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/16 18:27:10 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	file_away(t_list *files, t_lexer *operator, t_lexer *word)
{
	printf("Dummy function\n");
	(void)files;
	(void)operator;
	(void)word;
}

// static t_list	*make_another_stinkin_heredoc(t_parser *node, t_list *list);
// t_file			*new_file_node(char *filename, int index, bool is_heredoc);

// void	create_docs(t_list *parser_list, t_god *god_struct)
// {
// 	t_parser	*node;

// 	while (parser_list)
// 	{
// 		node = parser_list->content;
// 		if (node->operator == HEREDOC)
// 			god_struct->heredoc_names
// 				= make_another_stinkin_heredoc(node, god_struct->heredoc_names);
// 		parser_list = parser_list->next;
// 	}
// 	return ;
// }

// static t_list	*make_another_stinkin_heredoc(t_parser *node, t_list *list)
// {
// 	int		id;
// 	char	*filename;
// 	char	*temp;
// 	int		file_exists;

// 	file_exists = 0;
// 	id = 0;
// 	filename = NULL;
// 	while (!file_exists)
// 	{
// 		free_string(&filename);
// 		temp = ft_itoa(id);
// 		filename = ft_strjoin("heredoc", temp);
// 		free_string(&temp);
// 		file_exists = access(filename, F_OK);
// 		id++;
// 	}
// 	node->fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
// 	if (!list)
// 		list = ft_lstnew(new_file_node(filename, node->index, true));
// 	else
// 		ft_lstadd_back(&list,
// 			ft_lstnew(new_file_node(filename, node->index, true)));
// 	return (list);
// }

// t_file	*new_file_node(char *filename, int index, bool is_heredoc)
// {
// 	t_file	*file_node;

// 	file_node = ft_calloc(1, sizeof(t_file));
// 	if (!file_node)
// 		return (NULL);
// 	file_node->index = index;
// 	file_node->filename = filename;
// 	file_node->temp = is_heredoc;
// 	return (file_node);
// }
