/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/30 14:37:43 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# define BAD_OPERATOR -1
# define CMD 1
# define ARG 2
# define FILE 3
# define DELIMITER 4
# define PIPE 5
# define INPUT 6
# define OUTPUT 7
# define HEREDOC 8
# define APPEND 9

# define TRIM 10

# define ECHO 11
# define CD 12
# define PWD 13
# define EXPORT 14
# define UNSET 15
# define ENV 16
# define EXIT 17

# define READ 0
# define WRITE 1

int	g_signal_received;

typedef struct s_lexer
{
	char	*string;
	int		token;
}				t_lexer;

typedef struct s_parser
{
	char	*cmd;
	char	**cmd_array;
	t_list	*cmd_list;
	t_list	*files;
	int		builtin;
}				t_parser;

typedef struct s_file
{
	int		fd;
	int		operator;
	char	*filename;
	char	*delimiter;
}				t_file;

typedef struct s_exec
{
	int		pid;
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];
	char	*cmd;
	char	**cmd_array;
	char	*path;
}				t_exec;

typedef struct s_god
{
	char	**env;
	t_list	*lexer_list;
	t_list	*parser_list;
	t_list	*exec_list;
	int		block_count;
}				t_god;

t_god	*create_god_struct(char **envp);
int		increment_shell_level(char **env);

void	await_signals(void);
void	await_input(t_god *tools);

int		parse(char *input_string, t_god *god_struct);
t_list	*create_parser_list(t_list *parser_list, t_list *lexer_list);
char	**expander(char **split_str, t_god *god_struct);

int		execute(t_god *god_struct, t_list *parser_list);

char	*get_env_var(char *var, char **env, int trim);
int		count_operators(const char *str, char c);
int		count_char(char *str, char c);

int		execute_builtins(char **cmd, int fd_out, t_god *god_struct);

char	*get_var(char *var, t_god *tools);
int		env(int fd_out, t_god *god_struct);
int		export(char **cmd, int fd_out, t_god *god_struct);
int		echo(char **cmd, int fd_out);
int		unset(char **cmd, t_god *god_struct);
int		pwd(int fd_out, t_god *god_struct);
int		cd(char *dir, t_god *god_struct);
void	exit_minishell(t_god *god_struct);

void	free_string(char **string);
void	free_string_array(char ***array);

void	free_god_struct(t_god **root);
void	free_lexer_node(void *node);
void	free_parser_node(void *node);
void	free_file_node(void *node);
void	free_exec_node(void *node);

int		close_fd(int fd);

void	print_lexer_list(t_list *lexer_list);
void	print_parser_list(t_list *parsed_list);
// void	print_heredoc_list(t_list *heredocs);
int		first_index_of(char *str, char c);
int		second_index_of(char *str, char c);

#endif
