/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/30 16:46:41 by Kekuhne          ###   ########.fr       */
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
	char	*raw_input;
	char	**cmd;
	char	*token;
	struct s_lexer	*next;
}				t_lexer;

typedef struct	s_envp
{
	char **env;
	char **sorted_env;
	t_lexer *lexer_struct;
}				t_envp;

void	lexer(t_envp *tools);
void	expander(t_lexer **root, t_envp *tools);
t_envp	*create_god_struct(char **envp);
void	await_input(t_envp *tools);
char	*read_user_input();
void	await_signals(void);
void	clear_input(int signal_number);
t_lexer	*lexer_list_init(char **str);
void	quit(int exit_number);
int	count_cmd(char **str);
int	check_token(char c);


char	*get_var(char *var, t_envp *tools);
int	env_build_in(t_envp *tools);
int	export_build_in(t_envp *tools, char **cmd);
int	echo_build_in(char **cmd, t_envp *tools);
int	unset_build_in(t_envp *tools, char **cmd);
int	pwd_build_in(t_envp *tools);
int	cd_build_in(char *dir, t_envp *tool);
#endif