# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 21:07:31 by tpetros           #+#    #+#              #
#    Updated: 2023/02/22 21:07:33 by tpetros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client

SERVER_SRC_FILES = server_files/server_utils.c server_files/server.c
CLIENT_SRC_FILES = client_files/client.c client_files/client_utils.c

CC = cc
RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

SERVER_OBJS = ${SERVER_SRC_FILES:.c=.o}
CLIENT_OBJS = ${CLIENT_SRC_FILES:.c=.o}

all: ${SERVER_NAME} ${CLIENT_NAME}

${SERVER_NAME}: ${SERVER_OBJS}
	cd ./libft/ && make
	${CC} ${CFLAGS} ${SERVER_OBJS} ./libft/libft.a -o ${SERVER_NAME}

${CLIENT_NAME}: ${CLIENT_OBJS}
	${CC} ${CFLAGS} ${CLIENT_OBJS} ./libft/libft.a -o ${CLIENT_NAME}

clean:
	cd ./libft/ && make clean
	${RM} ${SERVER_OBJS} ${CLIENT_OBJS}

fclean: clean
	cd ./libft/ && make fclean
	${RM} ${SERVER_NAME} ${CLIENT_NAME}

re:	fclean all