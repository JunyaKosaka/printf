/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:08:07 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/27 18:53:31 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#ifdef TEST

#include <stdio.h>

#ifdef FT_PRINTF
#define F(...)\
res = ft_printf(__VA_ARGS__)
#else
#define F(...)\
res = printf(__VA_ARGS__)
#endif

int	main(void)
{
	int	res;

	F("[%%]\n");
	F("[%%%%%%]\n");

	F("[foo]\n");
	F("[%s]\n", "bar");
	F("[%.5s]\n", "foo");
	F("[%.2s]\n", "foo");
	F("[%.2s]\n", NULL);
	F("[%c]\n", 'a');

	F("[% d]\n", 0);
	F("[%+d%d]\n", 123, -12345);
	F("[%+d, %d]\n", INT_MIN, INT_MAX);
	F("[%10.0d]\n", 0);
	F("[%.5d]\n", -123);
	F("[%   +++   d]\n", -123);
	F("[%+10.5d]\n", 987);
	F("[% +10.5d]\n", 987);
	F("[%010.5d]\n", 42);
	F("[%010d]\n", 123);
	F("[%-10.5d]\n", 123);
	F("[% *d]\n", 5, 123);
	F("[%10.*d]\n", 5, 123);
	F("[%*.*d]\n", 10, 5, 234);

	F("[%*i]\n", 5, 123);
	F("[%10.*i]\n", 5, 123);
	F("[%*.*i]\n", 10, 5, 234);

	F("[%u]\n", 10);
	F("[%u]\n", -1);

	F("[%x, %x]\n", 123456789, 0);
	F("[%x]\n", INT_MAX);
	F("[%x]\n", UINT_MAX);

	F("[%X, %X]\n", 123, 5555);
	F("[%X]\n", INT_MAX);
	F("[%X]\n", UINT_MAX);
	// F("[%99999999999d]\n", 234);  // *の引数やprecisionのINT_MAXを超えるものへの対応
	// int x = 42;
	// char	x = 'a';
	// F("[%p]\n", &x);
	// printf("res is %d\n", res);
	// int x = 123;
	// F("[%p]\n", &x);
	
	// 0 - # + [ ]の順番が異なる場合	
	return (0);
}

#endif // TEST

// #define FMT1 "|%c|%s|%p|%d|%i|%u|%x|%X|%%|\n"
// #define FMT2 "|%#c|%#s|%#p|%#d|%#i|%#u|%#x|%#X|%#%|\n"
// #define FMT3 "|%*c|%*s|%*p|%*d|%*i|%*u|%*x|%*X|%*%|\n"