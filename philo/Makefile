# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 16:34:37 by hulescur          #+#    #+#              #
#    Updated: 2026/05/15 17:31:15 by hulescur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/main.c src/parsing.c src/utils.c src/utils2.c src/time.c \
		src/routine.c src/philo.c \

CC = cc 
RM = rm -f
INC_DIR = includes
CFLAGS = -I$(INC_DIR) -Wall -Wextra -Werror -g

NAME = philo
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INC_DIR)/philo.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
