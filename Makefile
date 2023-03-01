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

SERVER_SRC = src/server.c 
CLIENT_SRC = src/client.c 

SERVER_SRC_BONUS = src_bonus/server_bonus.c 
CLIENT_SRC_BONUS = src_bonus/client_bonus.c 

CC = cc
RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

SERVER_OBJS = ${SERVER_SRC:.c=.o}
CLIENT_OBJS = ${CLIENT_SRC:.c=.o}

SERVER_OBJS_BONUS = ${SERVER_SRC_BONUS:.c=.o}
CLIENT_OBJS_BONUS = ${CLIENT_SRC_BONUS:.c=.o}

${SERVER_NAME}: ${SERVER_OBJS}
	cd ./libft/ && make
	${CC} ${CFLAGS} ${SERVER_OBJS} ./libft/libft.a -o ${SERVER_NAME}

${CLIENT_NAME}: ${CLIENT_OBJS}
	${CC} ${CFLAGS} ${CLIENT_OBJS} ./libft/libft.a -o ${CLIENT_NAME}

all: ${SERVER_NAME} ${CLIENT_NAME}

bonus: ${SERVER_NAME} ${CLIENT_NAME} ${SERVER_OBJS_BONUS} ${CLIENT_OBJS_BONUS}
	${CC} ${CFLAGS} ${SERVER_OBJS_BONUS} ./libft/libft.a -o ${SERVER_NAME}
	${CC} ${CFLAGS} ${CLIENT_OBJS_BONUS} ./libft/libft.a -o ${CLIENT_NAME}

clean:
	cd ./libft/ && make clean
	${RM} ${SERVER_OBJS} ${CLIENT_OBJS}
	${RM} ${SERVER_OBJS_BONUS} ${CLIENT_OBJS_BONUS}



fclean: clean
	cd ./libft/ && make fclean
	${RM} ${SERVER_NAME} ${CLIENT_NAME}

re:	fclean all
