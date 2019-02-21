# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 17:30:29 by bjovanov          #+#    #+#              #
#    Updated: 2019/01/10 17:30:30 by bjovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc

NAME = minishell

SRC_FILES  = main.c env.c execute.c builtins.c paths.c errors.c expansions.c

SRC_FILES += linked_list/add_env_item.c linked_list/count_env_items.c \
			 linked_list/new_env_item.c linked_list/find_env_item.c

SRC_FILES += expansions/tilde/tilde.c expansions/dollar/dollar.c

SRC  = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ  = $(addprefix $(OBJ_DIR)/, $(subst .c,.o, $(SRC_FILES)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB = -L libft/ -lft
LIBFT_INC = libft/includes

KNRM = "\x1B[0m"
KGRN = "\x1B[1;32m"

.PHONY: all clean fclean re

all:
	@mkdir -p $(OBJ_DIR)
	@make -C libft/
	@make $(NAME)

$(NAME): $(OBJ)
	@echo "Creation de l'executable..."
	@$(CC) $(CLFAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compilation du fichier "$(KGRN)$(notdir $(subst .c,,$<))$(KNRM)
	@mkdir -p $(dir $@) && $(CC) $(CFLAGS) -I $(LIBFT_INC) -I $(INC_DIR) -o $@ -c $<

clean:
	@make clean -C libft/
	@rm -rf $(OBJ_DIR)

fclean:
	@make fclean -C libft/
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

re: fclean all
