# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dly <dly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:22:17 by dly               #+#    #+#              #
#    Updated: 2022/11/12 14:31:27 by dly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c)

NAME	=	libft.a

OBJS	=	${.c=.o}

# HEADERS	=	includes/

CFLAGS	=	-Wall -Wextra -Werror

.c.o	:
			gcc ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJS}
			ar rc ${NAME} ${OBJS}

all		:	${NAME}

clean	:
			rm -f ${OBJS}

fclean	:	clean
			rm -f ${NAME}

re		:	fclean all