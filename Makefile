# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 17:23:28 by pdiedra           #+#    #+#              #
#    Updated: 2019/07/26 15:40:08 by skrystin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= lem_in

SRC_PATH		= ./src/
INCLUDE_PATH	= ./includes/
LIBFT_PATH		= ./libft/

SRC_NAME		= main.c ft_cons.c ft_create_map.c ft_create_matrix.c rooms.c ft_bfs_helper.c
SRC				= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ				= $(addprefix $(SRC_PATH), $(SRC_NAME:.c=.o))

FLAG			= -Wall -Wextra -Werror

CC				= gcc

all: $(NAME)

$(NAME): $(OBJ) lib
	@$(CC) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME) $(FLAG)
	@echo "$(NAME) is 👌"

%.o:%.c
	$(CC) -I $(INCLUDE_PATH) -I $(LIBFT_PATH)/$(INCLUDE_PATH) $(FLAG) -o $@ -c $<

lib:
	@make -C $(LIBFT_PATH)

relib:
	@make re -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all
