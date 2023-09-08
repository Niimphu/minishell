/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/07 21:16:51 by Kekuhne          ###   ########.fr       */
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

int	g_signal_received;

typedef struct s_parser
{
	char			**cmd;
	char			*operator;
	struct s_parser	*next;
}				t_parser;

typedef struct s_god
{
	char	**env;
	t_list	*parser_list;
}				t_god;

t_god	*create_god_struct(char **envp);

void	await_signals(void);	
void	await_input(t_god *tools);

t_list	*create_parser_list(char **split_string);
void	parse(char *input_string, t_god *god_struct);


int		next_command(char **str);
int		next_operator(char **str);
int		contains_operator(char c);
int		ends_with_operator(char **array);
void	expander(t_list **root, t_god *tools);

int		get_array_size(char **array);


char	*get_var(char *var, t_god *tools);
int		env(t_god *tgod_struct);
int		export(t_god *god_struct, char **cmd);
int		echo(char **cmd, t_god *tools);
int		unset(t_god *tools, char **cmd);
int		pwd(t_god *tools);
int		cd(char *dir, t_god *god_struct);
int		exit_minishell(t_god *god_struct);

void	free_god_struct(t_god **root);
void	free_parser_list(t_list *parsed_list);
void	free_string(char **string);
void	free_string_array(char ***array);

void	print_parser_list(t_list *parsed_list);
#endif
