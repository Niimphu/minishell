/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/03 15:59:59 by Kekuhne          ###   ########.fr       */
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

int	global_signal_number;

typedef struct s_lexer
{
	char			*raw_input;
	char			*cmd;
	char			*args;
	char			*token;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}				t_lexer;

typedef struct s_envp
{
	char	**env;
}			t_envp;

void	lexer(t_lexer *input);

void	await_input(char **envp);
void	await_signals(void);

void	quit(int exit_number);

#endif