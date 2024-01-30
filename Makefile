# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ivan-mel <ivan-mel@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/30 14:14:43 by iris          #+#    #+#                  #
#    Updated: 2024/01/26 14:33:56 by ivan-mel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		:= 	Cub3d
MLX			:=	./MLX42
MLX_A	:=	$(MLX)/build/libmlx42.a
LIBFT_A :=	./libft/libft.a
LIBFT_H	:=  ./libft/include/libft.h
HEADERS		:=	 -I include -I MLX42/include/MLX42 -I libft/include
LINKFLAGS	:= -lglfw -ldl -pthread -lm

RM 			:=	rm -rf
FLAGS 		:=	-Wall -Werror -Wextra -fsanitize=address -g
SRC			:=	main.c \
				characters.c \
				error.c \
				free.c \
				map.c \
				map_utils.c \
				parsing.c \
				parsing_utils.c \
				paths.c \
				elements.c \
				elements_utils.c \
				mlx.c

OBJ_DIR		:=	./obj
SRC_DIR 	:= 	./src


OBJ		:= 	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

all: $(NAME)

$(MLX_A):
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build

run: $(NAME)
	./Cub3d maps/map.cub

$(NAME): $(OBJ) $(LIBFT_A) $(MLX_A)
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@$(CC) $^ $(FLAGS) $(HEADERS) -o ${NAME} ${MLX_A} $(LINKFLAGS) $(LIBFT_A)
	@echo ${Green} Complete 😊 ${Color_off}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo ${Blue} Compiling: $< ${Color_Off}
	@$(CC) ${FLAGS} $(HEADERS) -c $< -o $@


$(OBJ_DIR):
	@mkdir -p $@

$(LIBFT_A) : $(LIBFT_H)
	@printf "$(C_GREEN)Compiling $(C_CYAN)LIBFT \n$(C_RESET)"
	make -C libft

# Set 'WITH_BONUS' option to make with bonus
# bonus:
# 	@${MAKE} WITH_BONUS=1 all

clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_off}
# @${MAKE} -C libft clean
# @${MAKE} -C ${MLX}/build clean
	@${RM} ${OBJ_DIR}

fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${RM} ${NAME}

ffclean: fclean
	@${MAKE} -C libft fclean
	@${RM} ${MLX}/build

re: fclean all

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
