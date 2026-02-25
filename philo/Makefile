# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 16:34:37 by hulescur          #+#    #+#              #
#    Updated: 2026/02/24 01:23:29 by akkolitozer      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/main.c src/parsing.c src/utils.c src/time.c \

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

NAME = philo
OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
