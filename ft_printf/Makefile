# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dly <dly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:22:17 by dly               #+#    #+#              #
#    Updated: 2022/11/30 15:45:25 by dly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME		=	ft_printf ft_print_char ft_print_hex ft_print_nbr \
					ft_print_percent ft_print_ptr ft_print_str \
					ft_print_utils

SRCS			= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS			= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES))) 

SRCS_DIR		= srcs/
OBJS_DIR		= objs/
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I.
RM				= rm -f
AR				= ar rcs

NAME			= libftprintf.a
HEADER			= include/ft_printf.h

all:			$(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c | objs 
				@echo "$Compiling: $<"
				@$(CC) $(CFLAGS) include -c $< -o $@

$(NAME):		$(OBJS) $(HEADER)
				@make -C libft
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)
				@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)
objs:			
				@mkdir -p objs

clean:
				@$(RM) $(OBJS_DIR)/$(OBJS) 
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
