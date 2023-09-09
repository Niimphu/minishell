/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/08 18:15:18 by yiwong           ###   ########.fr       */
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
# define PIPE 1
# define INPUT 2
# define OUTPUT 3
# define HEREDOC 4
# define APPEND 5

# define TRIM 6

int	g_signal_received;

typedef struct s_parser
{
	int		index;
	char	**cmd;
	int		operator;
	int		fd;
	bool	outfile;
}				t_parser;

typedef struct s_god
{
	char	**env;
	t_list	*parser_list;
	t_list	*heredoc_names;
}				t_god;

typedef struct s_file
{
	int		index;
	char	*filename;
	bool	temp;
}				t_file;

t_god	*create_god_struct(char **envp);
int		increment_shell_level(char **env);

void	await_signals(void);	
void	await_input(t_god *tools);

t_list	*create_parser_list(char **split_string);
int		parse(char *input_string, t_god *god_struct);

void	expander(t_list **root, t_god *god_struct);

int		get_array_size(char **array);
char	*get_env_var(char *var, char **env, int trim);

char	*get_var(char *var, t_god *tools);
int		env(t_god *tgod_struct);
int		export(t_god *god_struct, char **cmd);
int		echo(char **cmd, t_god *tools);
int		unset(t_god *tools, char **cmd);
int		pwd(t_god *god_struct);
int		cd(char *dir, t_god *god_struct);

int		exit_minishell(t_god *god_struct);

void	free_god_struct(t_god **root);
void	free_string(char **string);
void	free_string_array(char ***array);
void	free_parser_node(void *node);
void	free_file_node(void *node);
void	close_fd(int *fd);

void	print_parser_list(t_list *parsed_list);
void	print_heredoc_list(t_list *heredocs);

#endif
