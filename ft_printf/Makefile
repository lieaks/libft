# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dly <dly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:22:17 by dly               #+#    #+#              #
#    Updated: 2022/11/28 14:41:08 by dly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME		=	ft_printf ft_print_char ft_print_hex ft_print_nbr \
					ft_print_percent ft_print_ptr ft_print_str \
					ft_print_utils

SRCS			= $(addprefix $(SRCS_DIR), $(addsuffix $(SRCS_FILES)))
OBJS			= $(addprefix $(OBJS_DIR), $(addsuffix $(SRCS_FILES))) 

SRCS_DIR		= srcs/
OBJS_DIR		= objs/
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I.
RM				= rm -f
AR				= ar rcs

NAME			= libftprintf.a
HEADER			= ft_printf.h

all:			$(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@echo "$Compiling: $<"
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS) $(HEADER)
				$(AR) $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:
				@norminette $(SRCS)

.PHONY:			all clean fclean re bonus
