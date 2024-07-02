# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 14:14:43 by iris              #+#    #+#              #
#    Updated: 2024/07/02 17:10:43 by ivan-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= 	cub3D
WARNING_FLAGS 			:= -Werror -Wextra -Wall -fsanitize=address -g
INCLUDE_FLAG	:=	-I libft/include -Iinclude/ -I MLX42/include/MLX42

HEADER			:= include/cub3d.h
MLX				:=	./MLX42
MLX_A			:=	$(MLX)/build/libmlx42.a
LIBFT_A			:=	./libft/libft.a

RM 			:=	rm -rf
OS_NAME	:= $(shell uname -s)
ifeq ($(OS_NAME), Darwin)
LIB_FLAGS := -lglfw -L "/usr/local/Cellar/glfw/3.4/lib" -framework Cocoa \
	-framework OpenGL -framework IOKit
else
LIB_FLAGS := -lglfw -ldl -pthread -lm
endif

SRC			:=	main.c \
				parser/characters.c \
				parser/error.c \
				parser/map.c \
				parser/map_utils.c \
				parser/parsing.c \
				parser/parsing_utils.c \
				parser/elements.c \
				parser/elements_utils.c \
				setup/mlx_setup.c \
				setup/player_setup.c \
				movement.c \
				movement_utils.c \
				raycast.c \
				raycast_utils.c \
				init_and_free.c \
				minimap/minimap.c \
				minimap/minimap_image.c \
				minimap/minimap_utils.c \
				textures.c \
				calculations.c \

#OBJB_FILES	=	$(SRCB:.c=.o)
OBJ_DIR		:=	./obj
SRC_DIR 	:= 	./src




# Reset
Color_Off	=	"\033[0m"			# Text Reset
# Regular Colors
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White

OBJ			:= 	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ_DIRS	:=	$(dir $(OBJ))
SRC			:=	$(addprefix $(SRC_DIR)/,$(SRC))

all: $(NAME)

run: $(NAME)
	./$(NAME) maps/map_test.cub
	./$(NAME) maps/map_huge.cub
	./$(NAME) maps/map_corridor.cub
	./$(NAME) maps/map_small.cub
	./$(NAME) maps/map_error.cub

$(MLX_A):
	@if [ -z "$$(ls -A MLX42)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build

$(NAME): $(MLX_A) $(LIBFT_A) $(OBJ)
	@echo $(Blue) Building $(NAME) $(Color_Off)
	@$(CC) $^ $(LIBFT_A) $(MLX_A) $(WARNING_FLAGS) $(LIB_FLAGS) -o $(NAME)
	@echo $(Green) Complete 😊 $(Color_off)

$(LIBFT_A):
	@$(MAKE) -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIRS)
	@$(CC) $(WARNING_FLAGS) $(INCLUDE_FLAG) -c $< -o $@
	@echo $(Purple) $(notdir $@) $(Green) DONE $(Color_off)

clean:
	@echo $(Yellow) Deleting $(OBJ_DIR) $(Color_off)
	@$(RM) $(OBJ_DIR)


libclean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C $(MLX)/build clean

libfclean: libclean
	@$(MAKE) -C libft fclean
	@$(RM) $(MLX)/build

fclean: clean
	@echo $(Yellow) Deleting $(NAME) $(Color_off)
	@$(RM) $(NAME)

re: fclean all
