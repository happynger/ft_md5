# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 19:28:19 by ori               #+#    #+#              #
#    Updated: 2019/01/28 15:12:01 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ssl
FT_LIB		= libft.a

SRCDIR		= ./src
HASHDIR		= $(SRCDIR)/hashes
OBJDIR		= ./obj

SRC			= command_handler.c \
			  main.c \
			  globals.c \
			  printer.c \
			  error_handler.c \
			  $(addprefix hashes/,$(shell ls $(HASHDIR)/ | grep -E ".+\.c"))

OBJ			= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O3

RED			= \033[0;31m
GREEN		= \033[0;32m
BLUE		= \033[0;34m
CYAN		= \033[0;36m
RESET		= \033[0m

FT			= ./libft
FT_LINK		= -L $(FT)/ -lft
FT_INC		= -I $(FT)/includes

INC			= -I ./includes

all: obj $(FT_LIB) $(NAME)

obj:
	@echo "$(BLUE)Creating Object Folders$(RESET)"
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/hashes

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@echo "$(GREEN)"
	$(CC) $(CFLAGS) $(INC) $(FT_INC) -o $@ -c $<
	@echo "$(RESET)"

$(FT_LIB):
	@echo "$(GREEN)"
	@echo "CREATING THE LIBFT$(CYAN)"
	@make -C $(FT)
	@echo "$(RESET)"

$(NAME): $(OBJ)
	@echo "$(GREEN)"
	$(CC) $(CFLAGS) $(OBJ) $(FT_LINK) -o $(NAME)
	@echo "$(RESET)"

clean:
	@echo
	@echo "$(RED)Deleting the obj files$(RESET)"
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean

fclean: clean
	@echo "$(RED)Deleting the executable and library$(RESET)"
	@rm -rf $(NAME)
	@make -C $(FT) fclean

re: fclean all

git:
	@git add .
	@git commit -m "Automated Update $(shell date | head -c 19 | tail -c 15 && echo)"
	@git push
	@echo "The update was pushed to the github"
