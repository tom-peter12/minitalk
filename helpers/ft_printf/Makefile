# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 20:52:50 by tpetros           #+#    #+#              #
#    Updated: 2023/01/10 20:52:52 by tpetros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILES = ft_puthex.c ft_printf.c ft_putpointer.c ft_putunsignednbr.c \
			ft_writer.c ft_putchar.c ft_putnbr.c ft_putstr.c \
			ft_strlen.c

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRC_FILES:.c=.o}

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re:	fclean all
