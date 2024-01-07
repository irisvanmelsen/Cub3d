# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 17:13:38 by ivan-mel          #+#    #+#              #
#    Updated: 2023/03/22 15:11:36 by ivan-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
				ft_lstnew_bonus.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
				ft_tolower.c ft_toupper.c get_next_line.c get_next_line_utils.c \
				hexafunctions.c printfunctions.c ft_printf.c

SRCB		=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c \
				ft_lstmap_bonus.c 

RM 			=	rm -f

NAME 		= 	libft.a

FLAGS 		=	-Wall -Werror -Wextra

CC 			= 	gcc

OBJ			=	${SRC:.c=.o}

OBJB		=	${SRCB:_bonus.c=_bonus.o}

AR 			=	ar -rc

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

${NAME}: ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${AR} ${NAME} $?
	@echo ${Green} Complete 😊 ${Color_off}

all:	${NAME}

%.o: %.c
	@echo ${Blue} Compiling: $< ${Color_Off}
	@${CC} ${FLAGS} -c $<

bonus:	$(NAME) ${OBJB}
	@echo ${Blue} Building ${NAME} with bonus ${Color_Off}
	@${AR} ${NAME} $?
	@echo ${Green} Bonus Complete 😊 ${Color_off}

clean:
	@echo ${Yellow} Cleaning ${Color_off}
	@${RM} ${OBJ} ${OBJB}

fclean: clean
	@echo ${Yellow} Cleaning archive ${Color_off}
	@${RM} ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re
