# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 12:22:10 by Kekuhne           #+#    #+#              #
#    Updated: 2023/10/14 15:43:46 by Kekuhne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define SHELF
==========================================================================
\033[0;33m
       ||.--.    .-._                        .----.             ||
       |||==|____| |H|___            .---.___|""""|_____.--.___ ||
       |||  |====| | |xxx|_          |+++|=-=|_  _|-=+=-|==|---|||
       |||==|    | | |   | \         |   |   |_\/_|Kevin|  | ^ |||
       |||  |LMAO| | |   |\ \   .--. |   |=-=|_/\_|-=&=-|  | ^ |||
       |||  |    | | |   |_\ \_( oo )|   |   |    |Yison|  | ^ |||
       |||==|====| |H|xxx|  \ \ |''| |+++|=-=|""""|-=+=-|==|---|||
       ||`--^----'-^-^---'   `-' ""  '---^---^----^-----^--^---^||
       ||-------------------------------------------------------||
       ||_______________________________________________________||\033[0m
	                _       _      __         ______
	     ____ ___  (_)___  (_)____/ /_  ___  / / __/
	    / __ `__ \/ / __ \/ / ___/ __ \/ _ \/ / /_
	   / / / / / / / / / / (__  ) / / /  __/ / __/
	  /_/ /_/ /_/_/_/ /_/_/____/_/ /_/\___/_/_/

==========================================================================

endef

export SHELF

NAME = minishell

CC = gcc
CC += -g -O0
#CC += -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

LIBS = -L ~/.brew/Cellar/readline/8.2.1/lib -lreadline -lncurses

HEADERS = -I ~/.brew/Cellar/readline/8.2.1/include

#LIBS = -L /usr/local/Cellar/readline/8.2.1/lib -lreadline -lncurses
#
#HEADERS = -I /usr/local/Cellar/readline/8.2.1/include

LIBFT = build/libft.a

SRC_DIR = src

OBJ_DIR = build

SRC	=	main.c \
		await_input.c \
		init/create_struct.c \
		init/shell_level.c \
		signals/signals.c \
		signals/child_signals.c \
		parser/lexer.c \
		parser/lexer_utils.c \
		parser/lexer_list.c \
		parser/check_syntax.c \
		parser/parser.c \
		parser/parser_utils.c \
		parser/parser_list.c \
		parser/parser_list_utils.c \
		executer/execute.c \
		executer/execute_list.c \
		executer/execute_utils.c \
		executer/execute_builtins.c \
		file_managers/files.c \
		file_managers/heredoc.c \
		file_managers/file_list.c \
		expander/expander.c \
		expander/expander_utils.c \
		utils/checkers.c \
		utils/env_utils.c \
		free/free.c \
		free/free_structs.c \
		builtins/cd.c \
		builtins/echo.c \
		builtins/env.c \
		builtins/export.c \
		builtins/pwd.c \
		builtins/unset.c \
		builtins/exit.c

OBJ =	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
RESET = \033[0m

all: $(NAME)
	@if [ -e "$(NAME)" ]; then \
		echo "$(GREEN)Done!$(RESET)"; \
	else \
		echo "$(RED)Compilation failed :($(RESET)"; \
	fi

$(NAME): $(OBJ) $(LIBFT)
	clear
	@echo "$$SHELF"
	@echo "$(PURPLE)Compiling minishelf...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LIBS)
	@chmod a+x $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@make -sC ./libft
	@mv libft/libft.a build/libft.a

clean:
	@echo "$(BLUE)Cleaning... $(RESET)"
	@find $(OBJ_DIR) -name '*.o' -exec rm -f {} +
	@make clean -sC ./libft
	@rm -f build/libft.a
	@echo "$(GREEN)Cleaning complete!$(RESET)"

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re