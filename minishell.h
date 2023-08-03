/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:20:00 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/02 14:30:50 by Kekuhne          ###   ########.fr       */
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

typedef struct	s_lexer
{
	char	*raw_input;
	char	*cmd;
	char	*args;
	char	*token;
	struct	s_lexer *next;
	struct	s_lexer *prev;
}				t_lexer;

typedef struct	s_envp
{
	char **env;
}				t_envp;

#endif