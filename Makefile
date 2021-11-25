# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2021/11/25 18:37:23 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = *.c ./utils/*.c ./libft/*.c

OBJS = $(SRCS:%.c=%.o)

all: ft_printf

test:
	./test.sh

ft_printf: libftprintf.c
	gcc -D TEST -D FT_PRINTF $(SRCS) -o ft_printf

printf: libftprintf.c
	gcc -Wno-format -D TEST $(SRCS) -o printf

clean:
	rm ft_printf printf
