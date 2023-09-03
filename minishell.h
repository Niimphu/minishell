/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/02 17:23:55 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

int	g_signal_received;

typedef struct	s_lexer
{
	char			**cmd;
	char			*operator;
	struct s_lexer	*next;
}				t_lexer;

typedef struct	s_envp
{
	char	**env;
	char	**sorted_env;
	t_list	*lexer_list;
}				t_envp;

t_envp	*create_god_struct(char **envp);

void	await_input(t_envp *tools);
void	await_signals(void);

t_list	*create_lexer_list(char **split_string);
void	lexer(char *input_string, t_envp *god_struct);

int		count_cmd(char **str);
int		contains_operator(char c);
int		ends_with_operator(char **array);

void	expander(t_list **root, t_envp *tools);

int		get_array_size(char **array);

void	free_string(char **string);

void	quit(int exit_number);

char	*get_var(char *var, t_envp *tools);
int		env_build_in(t_envp *tools);
int		export_build_in(t_envp *tools, char **cmd);
int		echo_build_in(char **cmd, t_envp *tools);
int		unset_build_in(t_envp *tools, char **cmd);
int		pwd_build_in(t_envp *tools);
int		cd_build_in(char *dir, t_envp *tool);
#endif