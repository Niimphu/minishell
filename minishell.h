/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/15 19:55:32 by yiwong           ###   ########.fr       */
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

int	g_signal_received;

typedef struct s_lexer
{
	char	*string;
	int		token;
}				t_lexer;

typedef struct s_parser
{
	char	**cmd;
	t_list	*cmd_list;
	t_list	*files;
	bool	builtin;

}				t_parser;

typedef struct s_file
{
	int		fd;
	int		operator;
	char	*filename;
	bool	heredoc;
	char	*delimiter;
}				t_file;

typedef struct s_god
{
	char	**env;
	t_list	*lexer_list;
	t_list	*parser_list;
	t_list	*heredoc_names;
}				t_god;

//do #include "parser.h" from relevant files
// because parser.h includes this header file already

//# include "src/parser/parser.h"

t_god	*create_god_struct(char **envp);
int		increment_shell_level(char **env);

void	await_signals(void);
void	await_input(t_god *tools);

t_list	*create_parser_list(t_god *god_struct, t_list *lexer_list);
int		parse(char *input_string, t_god *god_struct);

char	**expander(char **split_str, t_god *god_struct);

//int		get_array_size(char **array);
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


void	free_god_struct(t_god **root);
void	free_string(char **string);
void	free_string_array(char ***array);
void	free_lexer_node(void *node);
void	free_parser_node(void *node);
void	free_file_node(void *node);

void	close_fd(int *fd);

void	print_lexer_list(t_list *lexer_list);
 void	print_parser_list(t_list *parsed_list);
// void	print_heredoc_list(t_list *heredocs);

#endif
