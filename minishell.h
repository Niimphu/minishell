/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/22 17:50:25 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>

extern int	g_signal_received;

typedef struct s_lexer
{
	char			*raw_input;
	char			**cmd;
	char			*token;
	struct s_lexer	*next;
}				t_lexer;

typedef struct s_envp
{
	char	**env;
	char	**sorted_env;
	t_lexer	*lexer_struct;
}				t_envp;

t_envp	*create_god_struct(char **envp);

t_lexer	*lexer_list_init(char **str);
void	lexer(t_envp *tools);

int		count_cmd(char **str);
int		check_token(char c);

void	expander(t_lexer **root, t_envp *tools);

void	await_input(t_envp *tools);
void	await_signals(void);

void	quit(int exit_number);

#endif