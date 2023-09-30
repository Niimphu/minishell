/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:37:12 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/30 13:52:46 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fork_this_shit_im_out(t_god *god_struct, t_exec *exec_node);
static void	make_a_child_____process(t_god *god_struct, t_exec *exec_node);

int	execute(t_god *god_struct, t_list *parser_list)
{
	t_exec		*exec_node;
	int			i;

	i = 0;
	open_heredocs(parser_list);
	open_files(parser_list);
	god_struct->exec_list = create_execution_list(parser_list);
	if (pipe_up(god_struct->exec_list))
		perror("sad\n");
	print_exec_list(god_struct->exec_list);
	while (++i <= god_struct->block_count)
	{
		exec_node = god_struct->exec_list->content;
		fork_this_shit_im_out(god_struct, exec_node);
		
		parser_list = parser_list->next;
	}
	//rest std?
	return (0);
}

static int	fork_this_shit_im_out(t_god *god_struct, t_exec *exec_node)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (perror("fork 🍴:"), 0);
	if (pid == 0)
		make_a_child_____process(god_struct, exec_node);
	else
		{}
	return (0);
}

static void	make_a_child_____process(t_god *god_struct, t_exec *exec_node)
{
	// char *exe;
	int	error;

	(void)error;
	exec_node->path = find_exec(exec_node, god_struct->env);
	printf("child kill\n");
	exit(0);
	error = 0;
	if (exec_node->fd_in > -1)
	{
		exec_node->fd_in = close_fd(exec_node->fd_in);
		dup2(exec_node->fd_in, STDIN_FILENO);
	}
} 

void	print_exec_list(t_list *exec_list)
{
	t_exec	*node;
	int			i;

	printf("\n\n=== Executor linked list ===\n\n");
	while (exec_list)
	{
		i = 0;
		node = (t_exec *)exec_list->content;
		printf("Executable commands: ");
		while (node->cmd_array[i])
			printf("%s ", node->cmd_array[i++]);
		printf("\nPath: %s\n", node->path);
		printf("\n\n====       FDs       ====\n");
		printf("FD in: %i\n", node->fd_in);
		printf("FD out: %i (%spipe)\n", node->fd_out, (node->fd_out == node->pipe_fd[WRITE]) ? "" : "not ");
		printf("====    End of FDs   ====\n");
		printf("\n\n");
		if (!exec_list->next)
			printf("===    End of list     ===\n\n\n");
		exec_list = exec_list->next;
	}
}
