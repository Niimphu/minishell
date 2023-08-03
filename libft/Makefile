# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 19:36:14 by kekuhne           #+#    #+#              #
#    Updated: 2023/06/15 18:19:31 by Kekuhne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRC		=	$(shell find src -iname "*.c")
OBJ		=	$(SRC:.c=.o)

OBJS_DIR = objs/
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJ))


$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ)
	@echo '$(NAME) created.'


$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	
clean:
	$(RM) $(OBJ)

fclean: clean 
		$(RM) $(NAME)

re: fclean all