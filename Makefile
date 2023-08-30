# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 12:22:10 by Kekuhne           #+#    #+#              #
#    Updated: 2023/08/30 16:48:12 by Kekuhne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc -Wall -Wextra -Werror -g

LIBS = -L ~/.brew/Cellar/readline/8.2.1/lib -lreadline -lncurses

HEADERS = -I ~/.brew/Cellar/readline/8.2.1/include

LIBFT = libft.a

SRC_DIR = src

OBJ_DIR = build

SRC	=	main.c \
		lexer/lexer.c \
		lexer/get_input.c \
		expander/expander.c \
		init/create_struct.c \
		list_functions/lexer_list.c \
		keybinds/keypress.c \
		quit/quit.c \
		buildin/cd_build_in.c \
		buildin/echo_build_in.c \
		buildin/export_build_in.c \
		buildin/pwd_build_in.c \
		buildin/unset_build_in.c \

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
	@echo "$(PURPLE)Compiling minishell...$(RESET)"
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