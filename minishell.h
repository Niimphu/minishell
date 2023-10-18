/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/10/18 13:34:15 by Kekuhne          ###   ########.fr       */
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
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# include "src/parser/lexer.h"

# define FAIL -1

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
# define PWD 12
# define EXPORT 13
# define ENV 14
# define CD 15
# define UNSET 16
# define EXIT 17

# define READ 0
# define WRITE 1

extern int	g_signal_received;

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
	int		builtin;
	char	*path;
}				t_exec;

typedef struct s_god
{
	struct termios	*og_termios;
	char			**env;
	t_list			*lexer_list;
	t_list			*parser_list;
	t_list			*exec_list;
	int				blocks;
	int				exit_status;
}				t_god;

t_god	*create_god_struct(char **envp);
int		increment_shell_level(t_god *god_struct, char **env);

void	await_input(t_god *tools);

int		parse(char *input_string, t_god *god_struct);
t_list	*create_parser_list(t_list *parser_list, t_list *lexer_list);
char	**expander(char **split_str, t_god *god_struct);
char	**new_env(t_god *god_struct, char *cmd);

int		execute(t_god *god_struct, t_list *parser_list);

char	*get_env_var(char *var, char **env, int trim);
int		verify_identifier(char *func, char *cmd);
char	*get_var(char *var, t_god *tools);
int		first_index_of(char *str, char c);

//int		count_operators(const char *str, char c);
//int		count_char(char *str, char c);
bool	is_valid_int(char *string);
bool	is_path(char *string);

int		execute_builtins(char **cmd, t_god *god_struct);

void	free_string(char **string);
void	free_string_array(char ***array);

void	free_god_struct(t_god **root);
void	free_lexer_node(void *node);
void	free_parser_node(void *node);
void	free_file_node(void *node);
void	free_exec_node(void *node);

int		close_fd(int fd);

int		new_split_size(char **split);
char	**cpy_env(char **env, int size);
void	print_lexer_list(t_list *lexer_list);
void	print_parser_list(t_list *parsed_list);
void	print_exec_list(t_list *exec_list);

#endif
