# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2021/12/01 00:55:48 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADERFILE = ft_printf.h

SRCS = ft_parse_spec.c ft_print_c.c ft_print_d.c ft_print_lx.c \
	ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c \
	ft_print_percent.c ./utils/ft_get_digits.c ./utils/ft_putchr.c ./utils/ft_foundchr.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make $(FLAGS) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $@ $^

all	: $(NAME)

%.o : %.c $(HEADERFILE)
	gcc $(FLAGS) -c $< -o $@

bonus : all

clean :
	make clean -C ./libft
	/bin/rm -rf $(OBJS)

fclean : clean
	make fclean -C ./libft
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus


# SRCS = ft_parse_spec.c ft_print_c.c ft_print_d.c ft_print_lx.c \
# 	ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c \
# 	./utils/ft_get_digits.c ./utils/ft_putchr.c main.c ./libft/*.c

# all: ft_printf

# test: $(SRCS)
# 	./test.sh

# ft_printf: $(SRCS)
# 	gcc -D TEST -D FT_PRINTF $(SRCS) -o ft_printf

# printf: $(SRCS)
# 	gcc -Wno-format -D TEST $(SRCS) -o printf

# clean:
# 	rm ft_printf printf