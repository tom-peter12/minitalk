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

SERVER_SRC_FILES = server/server_utils.c server/server.c
# CLIENT_SRC_FILES = client/client.c client/client_utils.c

CC = cc
RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

SERVER_OBJS = ${SERVER_SRC_FILES:.c=.o}
# CLIENT_OBJS = ${CLIENT_SRC_FILES:.c=.o}

all: ${SERVER_NAME}

${SERVER_NAME}: ${SERVER_OBJS}
	cd ./libft/ && make
	${CC} ${CFLAGS} ${SERVER_OBJS} ./libft/libft.a -o ${SERVER_NAME}

clean:
	cd ./libft/ && make clean
	${RM} ${SERVER_OBJS} 

fclean: clean
	cd ./libft/ && make fclean
	${RM} ${SERVER_NAME}

re:	fclean all
