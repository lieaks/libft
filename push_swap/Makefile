# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dly <dly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:22:17 by dly               #+#    #+#              #
#    Updated: 2022/12/27 14:04:19 by dly              ###   ########.fr        #
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
					way.c  free_stack.c  get_link.c is_sorted.c \
					last_rotate.c  algo.c  ready_a_b.c  set_default_link.c \

# SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			= $(SRCS:.c=.o)

# SRCS_DIR		= srcs/
INCLUDE			= -I. 
CC				= cc
CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f
AR				= ar rcs

NAME			= push_swap
NAME_LIB		= push_lib.a
HEADER			= push_swap.h

################################################################################
#                                                                              #
#                                  RULES                                       #
#                                                                              #
################################################################################

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				@$(AR) $(NAME_LIB) $(OBJS)
				@$(CC) $(SRCS_MAIN) $(NAME_LIB) -o $(NAME) 
				@echo "push_swap executable ready!"

%.o:			%.c
				@echo "Compiling: $<"
				@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 
				
clean:
				@$(RM) $(OBJS) 
				@echo "push_swap object files cleaned!"

fclean:			clean
				@$(RM) $(NAME) $(NAME_LIB)
				@echo " executable files cleaned!"

re:				fclean $(NAME) 

norm:
				@norminette $(SRCS) $(HEADER) 

.PHONY:			all clean fclean re bonus
