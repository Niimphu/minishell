/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:41:11 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/17 18:54:16 by Kekuhne          ###   ########.fr       */
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
	free_string_array(&parser_node->cmd_array);
	ft_lstclear(&(parser_node->files), free_file_node);
	free(node);
	node = NULL;
}

void	free_file_node(void *node)
{
	t_file	*file_node;

	file_node = (t_file *)node;
	if (file_node->heredoc)
	{
		unlink(file_node->filename);
		free_string(&file_node->filename);
	}
	free(node);
	node = NULL;
}

void	free_god_struct(t_god **ptr)
{
	t_god	*god_struct;

	god_struct = *(ptr);
	free_string_array(&god_struct->env);
	ft_lstclear(&god_struct->parser_list, free_parser_node);
	free(god_struct);
	god_struct = NULL;
	*ptr = NULL;
}

/* 
==13527== 16 bytes in 1 blocks are still reachable in loss record 17 of 102
==13527==    at 0x100128545: malloc (in /usr/local/Cellar/valgrind/HEAD-6ff08b6/libexec/valgrind/vgpreload_memcheck-amd64-darwin.so)
==13527==    by 0x100007ACE: ft_split (in ./minishell)
==13527==    by 0x100004172: split_input (lexer.c:69)
==13527==    by 0x100004043: lex (lexer.c:43)
==13527==    by 0x10000499C: parse (parser.c:24)
==13527==    by 0x100004DC3: await_input (get_input.c:26)
==13527==    by 0x100003CD1: main (main.c:32)

		5 bytes in 1 blocks are still reachable in loss record 1 of 102
==13527==    at 0x100128545: malloc (in /usr/local/Cellar/valgrind/HEAD-6ff08b6/libexec/valgrind/vgpreload_memcheck-amd64-darwin.so)
==13527==    by 0x100007A20: word_dup (in ./minishell)
==13527==    by 0x100007968: split_loop (in ./minishell)
==13527==    by 0x100007B08: ft_split (in ./minishell)
==13527==    by 0x100004172: split_input (lexer.c:69)
==13527==    by 0x100004043: lex (lexer.c:43)
==13527==    by 0x10000499C: parse (parser.c:24)
==13527==    by 0x100004DC3: await_input (get_input.c:26)
==13527==    by 0x100003CD1: main (main.c:32)

==13527== LEAK SUMMARY:
==13527==    definitely lost: 0 bytes in 0 blocks
==13527==    indirectly lost: 0 bytes in 0 blocks
==13527==      possibly lost: 0 bytes in 0 blocks
==13527==    still reachable: 309,838 bytes in 223 blocks
==13527==         suppressed: 13,899 bytes in 161 blocks

input: exit

==13574== 16 bytes in 1 blocks are still reachable in loss record 17 of 102
==13574==    at 0x100128545: malloc (in /usr/local/Cellar/valgrind/HEAD-6ff08b6/libexec/valgrind/vgpreload_memcheck-amd64-darwin.so)
==13574==    by 0x100007ACE: ft_split (in ./minishell)
==13574==    by 0x100004172: split_input (lexer.c:69)
==13574==    by 0x100004043: lex (lexer.c:43)
==13574==    by 0x10000499C: parse (parser.c:24)
==13574==    by 0x100004DC3: await_input (get_input.c:26)
==13574==    by 0x100003CD1: main (main.c:32)

==13574== 5 bytes in 1 blocks are still reachable in loss record 1 of 102
==13574==    at 0x100128545: malloc (in /usr/local/Cellar/valgrind/HEAD-6ff08b6/libexec/valgrind/vgpreload_memcheck-amd64-darwin.so)
==13574==    by 0x100007A20: word_dup (in ./minishell)
==13574==    by 0x100007968: split_loop (in ./minishell)
==13574==    by 0x100007B08: ft_split (in ./minishell)
==13574==    by 0x100004172: split_input (lexer.c:69)
==13574==    by 0x100004043: lex (lexer.c:43)
==13574==    by 0x10000499C: parse (parser.c:24)
==13574==    by 0x100004DC3: await_input (get_input.c:26)
==13574==    by 0x100003CD1: main (main.c:32)

==13574== LEAK SUMMARY:
==13574==    definitely lost: 0 bytes in 0 blocks
==13574==    indirectly lost: 0 bytes in 0 blocks
==13574==      possibly lost: 0 bytes in 0 blocks
==13574==    still reachable: 309,838 bytes in 223 blocks
==13574==         suppressed: 13,899 bytes in 161 blocks

input:<< del cmd1 args1 | > file1 cmd2 args2 | >> file2 cmd3 args3
 */