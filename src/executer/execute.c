/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:37:12 by yiwong            #+#    #+#             */
/*   Updated: 2023/10/11 17:28:03 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	fork_this_shit_im_out(t_god *god_struct, t_exec *exec_node);
static void	make_a_child_____process(t_god *god_struct, t_exec *exec_node);
static int	wait_all(t_list *exec_list);
static void	error_exit(char *cmd, int status);

// global error number when cd <invalid dir>
// exit +"100" thinks + and 100 are separate but they should be together??
// valgrind --track-fds=yes --leak-check=full --trace-children=yes --show-leak-kinds=all  ./minishell

int	execute(t_god *god_struct, t_list *parser_list)
{
	t_list		*exec_list;
	t_exec		*exec_node;
	int			i;
	int			error;

	open_heredocs(parser_list);
	open_files(parser_list);
	god_struct->exec_list = create_execution_list(parser_list);
	if (pipe_up(god_struct->exec_list))
		perror("sad\n");
	exec_list = god_struct->exec_list;
	i = 0;
	while (++i <= god_struct->block_count)
	{
		exec_node = exec_list->content;
		if (exec_node->builtin > 10 && god_struct->block_count == 1
			&& exec_node->fd_out == 0)
			execute_builtins(exec_node->cmd_array, god_struct);
		else
			fork_this_shit_im_out(god_struct, exec_node);
		exec_list = exec_list->next;
	}
	close_all_pipes(god_struct->exec_list);
	error = wait_all(god_struct->exec_list);
	return (error);
}

static int	fork_this_shit_im_out(t_god *god_struct, t_exec *exec_node)
{
	await_child_signals();
	exec_node->pid = fork();
	if (exec_node->pid < 0)
		return (perror("fork 🍴:"), 0);
	if (exec_node->pid == 0)
		make_a_child_____process(god_struct, exec_node);
	return (0);
}

static void	make_a_child_____process(t_god *god_struct, t_exec *exec_node)
{
	int	error;

	error = 0;
	exec_node->path = find_exec(exec_node, god_struct->env);
    if (!exec_node->path && exec_node->builtin == 0)
        error_exit(exec_node->cmd, 127);
    if (is_dir(exec_node))
		error_exit(exec_node->cmd, 126);
	if (exec_node->fd_in == -1 || exec_node->fd_out == -1)
		exit(1);
	if (exec_node->fd_in > 0)
		dup2(exec_node->fd_in, STDIN_FILENO);
	exec_node->pipe_fd[READ] = close_fd(exec_node->pipe_fd[READ]);
	if (exec_node->fd_out > 0)
		dup2(exec_node->fd_out, STDOUT_FILENO);
	exec_node->pipe_fd[WRITE] = close_fd(exec_node->pipe_fd[WRITE]);
	close_all_pipes(god_struct->exec_list);
	if (exec_node->builtin > 10)
		error = execute_builtins(exec_node->cmd_array, god_struct);
	else if (execve(exec_node->path, exec_node->cmd_array, god_struct->env)
		== -1)
		error = 1;
	free_god_struct(&god_struct);
	exit(error);
}

static int	wait_all(t_list *exec_list)
{
	int		status;
	int		error_code;
	t_exec	*node;

	status = 0;
	error_code = 0;
	while (exec_list)
	{
		node = (t_exec *)exec_list->content;
		waitpid(node->pid, &status, 0);
		if (WIFEXITED(status))
			error_code = WEXITSTATUS(status);
		exec_list = exec_list->next;
	}
	return (error_code);
}

static void	error_exit(char *cmd, int status)
{
	write(2, "minishelf: ", 11);
	write(2, cmd, ft_strlen(cmd));
	if (*cmd == '/' && access(cmd, X_OK) == 0)
		ft_putstr_fd(": Is a directory\n", 2);
	else if (*cmd == '/' && access(cmd, F_OK) == 0)
		ft_putstr_fd(": Permission denied\n", 2);
	else if (*cmd == '/')
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": Command not found\n", 2);
	exit(status);
}

/*
void	print_exec_list(t_list *exec_list)
{
	t_exec	*node;
	int		i;

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
 */