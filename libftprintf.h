/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:42:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/25 23:59:37 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H_
# define LIBFTPRINTF_H_

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct	s_arg
{
	int	s;
	int	width;
	int	precision;
}	t_arg;

int	ft_printf(const char * restrict format, ...);
int	ft_print_s(t_arg *arg, va_list *ap);
int	ft_print_c(t_arg *arg, va_list *ap);

int	ft_print_d(t_arg *arg, va_list *ap);
int	ft_putchar(char c);
int	ft_get_digits(int x);

#endif // LIBFTPRINTF_H_