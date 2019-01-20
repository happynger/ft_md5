# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ori <ori@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 19:28:19 by ori               #+#    #+#              #
#    Updated: 2019/01/20 14:30:28 by ori              ###   ########.fr        #
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
			  $(addprefix hashes/,$(shell ls $(HASHDIR)/ | grep -E ".+\.c"))

OBJ			= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O3

FT			= ./libft
FT_LINK		= -L $(FT)/ -lft
FT_INC		= -I $(FT)/includes

INC			= -I ./includes

all: obj $(FT_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/hashes

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INC) $(FT_LINK) $(FT_INC) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FT_LINK) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean

re: fclean all

git:
	@git add .
	@git commit -m "Automated Update $(shell date | head -c 19 | tail -c 15 && echo)"
	@git push
	@echo "The update was pushed to the github"
