# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ivan-mel <ivan-mel@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/30 14:14:43 by iris          #+#    #+#                  #
#    Updated: 2024/02/12 16:19:08 by ivan-mel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		:= 	cub3d
LIBFT_A		:=	./libft/libft.a
HEADER		:=	-I libft/include -I include/ -I MLX42/include/MLX42
#MLX
MLX			:=	./MLX42
LIBS_MLX	:=	$(MLX)/build/libmlx42.a

RM 			:=	rm -rf
FLAGS 		:=	-g #-fsanitize=address #-Wall -Werror -Wextra
SRC			:=	main.c \
				cubed.c \
				parser/characters.c \
				parser/error.c \
				parser/free.c \
				parser/map.c \
				parser/map_utils.c \
				parser/parsing.c \
				parser/parsing_utils.c \
				parser/elements.c \
				parser/elements_utils.c \
				setup/mlx_setup.c \
				setup/pixel_setup.c \
				setup/player_setup.c \
				setup/movement_setup.c \
				mouse_move.c \
				vector_utils.c \
				raycast.c
# SRCB		:=

#OBJB_FILES	=	${SRCB:.c=.o}
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
# Avoid relinking in bonus
# ifdef WITH_BONUS
# 	NAME	:=	checker
# 	OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRCB:.c=.o))
# else
# 	OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
# endif
# Add obj directory to obj path
OBJ			:= 	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ_DIRS	:=	$(dir $(OBJ))
SRC			:=	$(addprefix $(SRC_DIR)/,$(SRC))

all: ${NAME}

run: $(NAME)
	./$(NAME) maps/map2.cub

$(LIBS_MLX):
	@if [ -z "$$(ls -A MLX42)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build

${NAME}: $(LIBS_MLX) ${LIBFT_A} ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${CC} $^ ${LIBFT_A} ${LIBS_MLX} ${FLAGS} -Iinclude -lglfw -ldl -pthread -lm -o ${NAME}
	@echo ${Green} Complete 😊 ${Color_off}

${LIBFT_A}:
	@${MAKE} -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIRS)
	@${CC} ${FLAGS} ${HEADER} -c $< -o $@
	@echo $(Purple) $(notdir $@) $(Green) DONE ${Color_off}

# Set 'WITH_BONUS' option to make with bonus
# bonus:
# 	@${MAKE} WITH_BONUS=1 all

clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_off}
	@${RM} ${OBJ_DIR}


libclean:
	@${MAKE} -C libft clean
	@${MAKE} -C ${MLX}/build clean

libfclean: libclean
	@${MAKE} -C libft fclean
	@${RM} ${MLX}/build

fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${RM} ${NAME}

re: fclean all
