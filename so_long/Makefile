# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dly <dly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:22:17 by dly               #+#    #+#              #
#    Updated: 2023/01/21 17:03:50 by dly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                                                              #
#                              VARIABLES                                       #
#                                                                              #
################################################################################

SRCS_FILES		= main.c  file.c  map.c  error.c  free.c  check.c \
				  init_struct.c  flood_fill.c  move.c  sprites.c

SRCS_DIR		= srcs/
M_SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
M_OBJS			= $(M_SRCS:.c=.o)

# BONUS_FILES		= 
# B_SRCS_DIR		= srcs/bonus/
# B_SRCS			= $(addprefix $(B_SRCS_DIR), $(BONUS_FILES))
# B_OBJS			= $(B_SRCS:.c=.o)

LIBFT_FILES		= ft_bzero.c  ft_calloc.c  ft_memset.c  ft_split.c \
				  ft_strncmp.c  ft_strlen.c  ft_strjoin.c  ft_strnstr.c \
				  ft_strjoin_free.c  ft_strchr.c  ft_strchrstr.c \
				  ft_putnbr_fd.c  ft_putstr_fd.c  ft_count_char.c \
				  ft_putchar_fd.c . ft_itoa.c

LIBFT_DIR		= libft/
L_SRCS			= $(addprefix $(LIBFT_DIR), $(LIBFT_FILES))
L_OBJS			= $(L_SRCS:.c=.o)

GNL_FILES		= get_next_line.c 
GNL_DIR			= gnl/
GNL_SRCS		= $(addprefix $(GNL_DIR), $(GNL_FILES))
GNL_OBJS		= $(GNL_SRCS:.c=.o)

INCLUDE			= -Lminilibx-linux -lmlx_Linux -lXext -lX11 -Iinclude -Iminilibx-linux
CC				= cc
# CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f
AR				= ar rcs

NAME			= so_long 
HEADER			= include/so_long.h
MLX_EX			= minilibx-linux/libmlx.a
# HEADER_B		= include/pipex_bonus.h

################################################################################
#                                                                              #
#                                  RULES                                       #
#                                                                              #
################################################################################

all:			$(NAME)

%.o:			%.c
				@echo "Compiling: $<"
				@$(CC) $(CFLAGS) -Iinclude -Iminilibx-linux -c $< -o $@

$(NAME):		$(L_OBJS) $(GNL_OBJS) $(M_OBJS) $(HEADER)
				@make -C ./minilibx-linux
				@$(CC) $(INCLUDE) $(M_OBJS) $(GNL_OBJS) $(L_OBJS) $(MLX_EX) -o $(NAME) 
#				@$(CC) $(M_OBJS) $(L_OBJS) -Iinclude -o $(NAME)
#				 @$(CC) $(M_OBJS) $(GNL_OBJS) $(L_OBJS) -Iinclude -lmlx -Lmlx -framework OpenGL -framework AppKit -o $(NAME)
				@echo "so_long executable ready!"
				
# bonus: 			$(L_OBJS) $(GNL_OBJS) $(B_OBJS) $(HEADER_B)
# 				@$(CC) $(CFLAGS) $(INCLUDE) $(L_OBJS) $(GNL_OBJS) $(B_OBJS) -o $(NAME)
# 				@echo "bonus executable ready!"
				
clean:
				@$(RM) $(M_OBJS) $(GNL_OBJS) $(L_OBJS)
				@echo "pipex & libft object files cleaned!"

fclean:			clean
				@$(RM) $(NAME) 
				@echo " executable files cleaned!"

re:				fclean $(NAME) 

norm:
				@norminette $(SRCS_FILES) $(LIBFT_FILES) $(HEADER) 

.PHONY:			all clean fclean re bonus
