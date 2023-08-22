/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/22 14:41:27 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "readline/include/readline/readline.h"

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
	char	*raw_input;
	char	**cmd;
	char	*token;
	struct s_lexer	*next;
}				t_lexer;

typedef struct s_envp
{
	char **env;
	char **sorted_env;
	t_lexer *lexer_struct;
}				t_envp;

void	lexer(t_lexer *input, t_envp *tools);
void	expander(t_lexer **root, t_envp *tools);

void	await_input(char **envp);
void	await_signals(void);

void	quit(int exit_number);

#endif