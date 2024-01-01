# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iris <iris@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 14:14:43 by iris              #+#    #+#              #
#    Updated: 2024/01/02 00:19:51 by iris             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= 	cub3d
LIBS		:=	./libft/libft.a
HEADER		:=	-I libft -I include/cub3d.h -I $(MLX)/include/MLX42
#MLX
MLX			:=	./MLX42
LIBS_MLX	:=	$(MLX)/build/libmlx42.a

RM 			:=	rm -rf
FLAGS 		:=	-Wall -Werror -Wextra
SRC			:=	main.c \
				characters.c \
				error.c \
				free.c \
				map.c \
				map_utils.c \
				parsing.c \
				parsing_utils.c \
				elements.c
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
OBJ		:= 	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

all: libmlx ${NAME}

libmlx:
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
	
${NAME}: ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${MAKE} -C libft
	@${MAKE} -C MLX42/build
	@${CC} $^ ${LIBS} ${LIBS_MLX} -Iinclude -ldl -pthread -lm -o ${NAME}
	@echo ${Green} Complete 😊 ${Color_off}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo ${Blue} Compiling: $< ${Color_Off}
	@${CC} ${FLAGS} ${HEADER} -c $< -o $@


$(OBJ_DIR):
	@mkdir $@

# Set 'WITH_BONUS' option to make with bonus
# bonus:
# 	@${MAKE} WITH_BONUS=1 all

clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_off}
	@${MAKE} -C libft clean
	@${MAKE} -C ${MLX}/build clean
	@${RM} ${OBJ_DIR}

fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${MAKE} -C libft fclean
	@${RM} ${MLX}/build 
	@${RM} ${NAME}

re: fclean all
