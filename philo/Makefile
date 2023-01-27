# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dly <dly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:22:17 by dly               #+#    #+#              #
#    Updated: 2023/01/26 15:26:00 by dly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                                                              #
#                              VARIABLES                                       #
#                                                                              #
################################################################################

SRCS_FILES		= main.c  free.c  init.c  utils.c  philo.c 

SRCS_DIR		= srcs/mandatory/
M_SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
M_OBJS			= $(M_SRCS:.c=.o)

BONUS_FILES		= main_bonus.c 

B_SRCS_DIR		= srcs/bonus/
B_SRCS			= $(addprefix $(B_SRCS_DIR), $(BONUS_FILES))
B_OBJS			= $(B_SRCS:.c=.o)


INCLUDE			= -Iinclude
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -pthread

RM				= rm -f
AR				= ar rcs

NAME			= philo 
NAME_B			= philo_bonus
HEADER			= include/philo.h
HEADER_B		= include/philo_bonus.h

################################################################################
#                                                                              #
#                                  RULES                                       #
#                                                                              #
################################################################################

all:			$(NAME)

%.o:			%.c
				@echo "Compiling: $<"
				@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

$(NAME):		$(M_OBJS) $(HEADER) 
				@$(CC) $(CFLAGS) $(INCLUDE) $(M_OBJS) -o $(NAME) 
				@echo "philo executable ready!"

bonus:			$(NAME_B) 

$(NAME_B):		$(B_OBJS) $(HEADER_B) 
				@$(CC) $(CFLAGS) $(INCLUDE) $(B_OBJS) -o $(NAME_B)
				@echo "philo_bonus executable ready!"
				
clean:
				@$(RM) $(M_OBJS) $(B_OBJS)
				@echo "every object files cleaned!"

fclean:			clean
				@$(RM) $(NAME) $(NAME_B)
				@echo "executable files cleaned!"

re:				fclean $(NAME) $(NAME_B) 

norm:
				@norminette $(M_SRCS) $(B_SRCS) $(HEADER) $(HEADER_B) 

.PHONY:			all clean fclean re bonus
