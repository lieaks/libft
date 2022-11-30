# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dly <dly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:22:17 by dly               #+#    #+#              #
#    Updated: 2022/11/30 20:06:35 by dly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES		=	ft_printf.c ft_print_char.c ft_print_hex.c ft_print_nbr.c \
					ft_print_percent.c ft_print_ptr.c ft_print_str.c \
					ft_print_utils.c ft_print_unsigned.c

SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES:.c=.o))

SRCS_DIR		= srcs/
INCLUDE			= -I include
CC				= cc
CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f
AR				= ar rcs

NAME			= libftprintf.a
HEADER			= include/ft_printf.h

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				@make -C ./libft
				@cp libft/libft.a $(NAME)
				$(AR) $(NAME) $(OBJS)
				@echo "ft_printf compiled!"

$(SRCS_DIR)%.o:	$(SRCS_DIR)%.c
				@echo "Compiling: $<"
				@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 
				
clean:
				@$(RM) $(OBJS) 
				@make clean -C libft
				@echo "ft_printf object files cleaned!"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) libft/libft.a 
				@echo "ft_printf executable files cleaned!"
				@echo "libft executable files cleaned!"

re:				fclean $(NAME)

norm:
				@norminette $(SRCS)

.PHONY:			all clean fclean re bonus
