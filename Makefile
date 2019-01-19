# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ori <ori@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 19:28:19 by ori               #+#    #+#              #
#    Updated: 2019/01/18 19:29:20 by ori              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ssl


git:
	@git add .
	@git commit -m "Automated Update $(shell date | head -c 19 | tail -c 15 && echo)"
	@git push
	@echo "The update was pushed to the github"
