# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 11:26:00 by sbalk             #+#    #+#              #
#    Updated: 2023/05/29 12:07:13 by sbalk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra -I
RM			= rm -f
SRC_DIR		= src/
SRCB_DIR	= srcb/
OBJ_DIR		= obj/
OBJB_DIR	= objb/
AR			= ar rcs
LIBFT		= libft
INCLUDE		= include

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	ft_printf				\
				ft_util					\
				ft_print_chars			\
				ft_print_nbrs			\
				ft_print_hex			\
				ft_parse

SRCB_FILES	=	ft_printf_bonus			\
				ft_util_bonus			\
				ft_print_chars_bonus	\
				ft_print_nbrs_bonus		\
				ft_print_hex_bonus		\
				ft_parse_bonus

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRCB		=	$(addprefix $(SRCB_DIR), $(addsuffix .c, $(SRCB_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJB 		= 	$(addprefix $(OBJB_DIR), $(addsuffix .o, $(SRCB_FILES)))

OBJF		= .cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)
				@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJB_DIR)%.o: $(SRCB_DIR)%.c | $(OBJBF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(OBJBF):
			@mkdir -p $(OBJB_DIR)

bonus:		$(OBJB)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJB)
			echo "$(GREEN)ft_printf with bonus compiled!$(DEF_COLOR)"

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf $(OBJB_DIR)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(SRCB) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm