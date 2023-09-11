# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 12:22:10 by Kekuhne           #+#    #+#              #
#    Updated: 2023/09/11 14:25:16 by Kekuhne          ###   ########.fr        #
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

CC = gcc -Wall -Wextra -Werror
CC += -g -O0
# CC += -fsanitize=address

LIBS = -L ~/.brew/Cellar/readline/8.2.1/lib -lreadline -lncurses

HEADERS = -I ~/.brew/Cellar/readline/8.2.1/include

LIBFT = libft.a

SRC_DIR = src

OBJ_DIR = build

SRC	=	main.c \
		init/create_struct.c \
		init/shell_level.c \
		parser/lexer.c \
<<<<<<< HEAD
		parser/lexer_utils.c \
=======
		parser/lexer_list.c \
>>>>>>> master
		parser/check_syntax.c \
		parser/parser.c \
		parser/get_input.c \
		parser/parser_utils.c \
		parser/parser_list.c \
		file_managers/heredoc.c \
		expander/expander.c \
		keybinds/keypress.c \
		utils/counters.c \
		utils/env_utils.c \
		free/free_char.c \
		free/free_structs.c \
		free/free_fd.c \
		quit/quit.c \
		builtins/cd.c \
		builtins/echo.c \
		builtins/export.c \
		builtins/pwd.c \
		builtins/unset.c \
		builtins/exit.c \

OBJ =	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
RESET = \033[0m

all: $(NAME)
	@if [ -e "$(NAME)" ]; then \
		echo "$(GREEN)Compilation successful!$(RESET)"; \
	else \
		echo "$(RED)Compilation failed :($(RESET)"; \
	fi

$(NAME): $(OBJ) $(LIBFT)
	clear
	@echo "$$SHELF"
	@echo "$(PURPLE)Compiling minishelf...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_DIR)/$(LIBFT) -o $(NAME) $(LIBS)
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