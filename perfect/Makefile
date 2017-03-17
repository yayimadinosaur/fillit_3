# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfung <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 18:33:10 by wfung             #+#    #+#              #
#    Updated: 2017/01/05 17:41:11 by wfung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = fillit

SRC = ./*.c 

OBJS = ./*.o

INCL = ./&.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(OBJS) $(NAME)

re: fclean all
