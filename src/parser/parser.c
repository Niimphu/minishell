/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:16:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/10 15:51:27 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// check for double or beginning operator
// handle oe or more heredoc
// input output files
// git branch -a 

int	parse(char *input, t_god *god_struct)
{
	t_list	*parsed_list;
	char	**split_str;

	split_str = lex(input);
	parsed_list = create_parser_list(split_str);
	god_struct->parser_list = parsed_list;
	expander(&parsed_list, god_struct);
	create_docs(parsed_list, god_struct);
	print_parser_list(god_struct->parser_list);
	print_heredoc_list(god_struct->heredoc_names);
	return (0);
}

void	print_parser_list(t_list *parsed_list)
{
	t_parser	*node;
	int			i;
	int			j;

	printf("\n=== Parser linked list ===\n\n");
	j = 0;
	while (parsed_list)
	{
		i = 0;
		node = (t_parser *)parsed_list->content;
		while (node->cmd[i])
		{
			printf("cmd[%d] of node %d is : %s\n", i, node->index, node->cmd[i]);
			i++;
		}
		printf("command line operator ID of node %d is: %i\n",
			j, node->operator);
		printf("fd for this node is %i\n", node->fd);
		printf("this node is%s an outfile\n\n", node->outfile ? "" : " not");
		j++;
		parsed_list = parsed_list->next;
	}
	printf("===    End of list     ===\n\n");
}

void	print_heredoc_list(t_list *heredocs)
{
	t_file	*node;

	printf("\n\n=== Heredoc linked list ===\n\n");
	while (heredocs)
	{
		node = (t_file *)heredocs->content;
		printf("heredoc name: %s\n", node->filename);
		printf("index: %i\n\n", node->index);
		heredocs = heredocs->next;
	}
	printf("===    End of list     ===\n\n");
}
