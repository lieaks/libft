# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dly <dly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:22:17 by dly               #+#    #+#              #
#    Updated: 2022/12/20 16:19:22 by dly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                                                              #
#                              VARIABLES                                       #
#                                                                              #
################################################################################

SRCS_MAIN		= 	main.c
SRCS			=	assign_rank.c  fill_stack.c  get_cost.c  get_two_last.c \
					main.c  pa_pb.c  rotate.c  swap.c \
					check_rotate_faster.c  free_stack.c  get_link.c \
					last_rotate.c  algo.c  ready_a_b.c  set_default_link.c \
					ft_printf.c ft_print_char.c ft_print_nbr.c \
					ft_print_utils.c 

# SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			= $(SRCS:.c=.o)

# SRCS_DIR		= srcs/
INCLUDE			= -I. 
CC				= cc
CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f
AR				= ar rcs

NAME			= push_swap
NAME_LIB		= push_lib
HEADER			= push_swap.h

################################################################################
#                                                                              #
#                                  RULES                                       #
#                                                                              #
################################################################################

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				@$(AR) $(OBJS) -o $(NAME_LIB) 
				@$(CC) $(SRCS_MAIN) -o $(NAME) 
				@echo "ft_printf compiled!"

%.o:			%.c
				@echo "Compiling: $<"
				@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 
				
clean:
				# $(RM) $(OBJS) 
				@echo "ft_printf object files cleaned!"

fclean:			clean
				@$(RM) $(NAME)
				@echo " executable files cleaned!"

re:				fclean $(NAME)

norm:
				@norminette $(SRCS) $(HEADER) 

.PHONY:			all clean fclean re bonus
