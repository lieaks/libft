# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dly <dly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:22:17 by dly               #+#    #+#              #
#    Updated: 2023/01/04 19:50:10 by dly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                                                              #
#                              VARIABLES                                       #
#                                                                              #
################################################################################

SRCS_FILES		= main.c  processes.c 
SRCS_DIR		= srcs/mandatory/
M_SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
M_OBJS			= $(M_SRCS:.c=.o)

LIBFT_FILES		= ft_bzero.c  ft_calloc.c  ft_memset.c  ft_split.c \
				  ft_strncmp.c  ft_strlen.c  ft_join.c
LIBFT_DIR		= libft/
L_SRCS			= $(addprefix $(LIBFT_DIR), $(LIBFT_FILES))
L_OBJS			= $(L_SRCS:.c=.o)

INCLUDE			= -I include/ 
CC				= cc
CFLAGS			= -g3 -Wall -Wextra -Werror

RM				= rm -f
AR				= ar rcs

NAME			= pipex 
HEADER			= include/pipex.h

################################################################################
#                                                                              #
#                                  RULES                                       #
#                                                                              #
################################################################################

all:			$(NAME) 

%.o:			%.c
				@echo "Compiling: $<"
				@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):		$(L_OBJS) $(M_OBJS) $(HEADER)
				@$(CC) $(M_OBJS) $(L_OBJS) -o $(NAME) 
				@echo "pipex executable ready!"
				
bonus			: $(SRCS_MAIN_CHECK) $(HEADER_GNL)
				@echo "checker executable ready!"
				@$(CC) $(SRCS_MAIN_CHECK) $(NAME_LIB) -o $(CHECKER_NAME) 
				
clean:
				@$(RM) $(M_OBJS) 
				@$(RM) $(L_OBJS)
				@echo "pipex & libft object files cleaned!"

fclean:			clean
				@$(RM) $(NAME) 
				@echo " executable files cleaned!"

re:				fclean $(NAME) 

norm:
				@norminette $(SRCS_FILES) $(LIBFT_FILES) $(HEADER) 

.PHONY:			all clean fclean re bonus
