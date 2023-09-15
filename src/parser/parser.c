/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:16:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/15 18:40:20 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// check for double or beginning operator
// handle oe or more heredoc
// input output files
// git branch -a 

int	parse(char *input, t_god *god_struct)
{
	char	**split_str;

	split_str = lex(input, god_struct);
	if (!split_str || !*split_str)
		return (-1);
		//just for testing
	execute_builtins(split_str, 1, god_struct);
	god_struct->lexer_list = create_lexer_list(split_str);
	if (invalid_syntax(god_struct->lexer_list))
		printf("minishelf: syntax error near unexpected token \'%c\'\n",
			*invalid_syntax(god_struct->lexer_list));
	else
		print_lexer_list(god_struct->lexer_list);

	ft_lstclear(&god_struct->lexer_list, free_lexer_node);
//	god_struct->parser_list = create_parser_list(split_str);
//	expander(&parsed_list, god_struct);
//	create_docs(parsed_list, god_struct);
//	print_parser_list(god_struct->parser_list);
//	print_heredoc_list(god_struct->heredoc_names);
	return (0);
}

char	*get_token_string(int id)
{
	if (id == CMD)
		return ("command");
	if (id == ARG)
		return ("argument");
	if (id == FILE)
		return ("file");
	if (id == PIPE)
		return ("pipe");
	if (id == INPUT)
		return ("in redirection");
	if (id == OUTPUT)
		return ("out redirection");
	if (id == HEREDOC)
		return ("heredoc");
	if (id == DELIMITER)
		return ("delimiter");
	if (id == APPEND)
		return ("append out redirection");
	return (NULL);
}

void	print_lexer_list(t_list *lexer_list)
{
	t_lexer	*node;

	printf("\n=== Lexer linked list ===\n\n");
	while (lexer_list)
	{
		node = (t_lexer *)lexer_list->content;
		printf("String: %s\n", node->string);
		printf("Token: %s\n\n", get_token_string(node->token));
		lexer_list = lexer_list->next;
	}
	printf("\n===    End of list    ===\n\n");
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
