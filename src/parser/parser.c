/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:16:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/03 12:20:47 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse(char *input, t_god *god_struct)
{
	char	**split_str;

	split_str = lex(input, god_struct);
	if (!split_str || !*split_str)
		return (-1);
	god_struct->lexer_list = create_lexer_list(split_str);
	if (invalid_syntax(god_struct->lexer_list))
	{
		printf("minishelf: syntax error near unexpected token \'%c\'\n",
			*invalid_syntax(god_struct->lexer_list));
		ft_lstclear(&god_struct->lexer_list, free_lexer_node);
		return (-1);
	}
	god_struct->parser_list
		= create_parser_list(god_struct->parser_list, god_struct->lexer_list);
	ft_lstclear(&god_struct->lexer_list, free_lexer_node);
	/* print_parser_list(god_struct->parser_list); */
	god_struct->block_count = ft_lstsize(god_struct->parser_list);
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
/* 
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
	printf("===    End of list    ===\n\n");
}

void	print_parser_list(t_list *parsed_list)
{
	t_parser	*node;
	t_list		*file_list;
	t_file		*file_node;
	int			i;

	printf("\n=== Parser linked list ===\n\n");
	while (parsed_list)
	{
		i = 0;
		node = (t_parser *)parsed_list->content;
		file_list = node->files;
		printf("Executable commands: ");
		while (node->cmd_array[i])
			printf("%s ", node->cmd_array[i++]);
		printf("\n");
		printf("======Files======\n");
		while (file_list)
		{
			file_node = (t_file *)(file_list->content);
			printf("Filename: %s\nDirection: %s\nDelimiter: %s\n", file_node->filename,
				get_token_string(file_node->operator), file_node->delimiter);
			if (file_list->next)
				printf("===Next file_list_node===\n");
			file_list = file_list->next;
		}
		printf("===End of files list===\n");
		printf("Is%sa built-in\n", node->builtin > 0 ? " " : " not ");
		printf("\n\n");
		if (!parsed_list->next)
			printf("===    End of list     ===\n\n");
		parsed_list = parsed_list->next;
	}
}
 */
