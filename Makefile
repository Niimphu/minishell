# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 12:22:10 by Kekuhne           #+#    #+#              #
#    Updated: 2023/08/03 16:29:37 by Kekuhne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc -Wall -Wextra -Werror -g

LIBS = -lreadline

LIBFT = libft.a

SRC_DIR = src

OBJ_DIR = build

SRC	=	main.c \
		lexer/lexer.c \

OBJ =	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LIBS)
	chmod a+x $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	cd libft && $(MAKE)
	mv libft/libft.a libft.a
	
clean:
	rm -f $(OBJ_DIR)/*/*.o
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C ./libft

re:	fclean all

.PHONY: all clean fclean re