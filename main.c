/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:08:07 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/26 23:53:31 by jkosaka          ###   ########.fr       */
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
	F("[foo]\n");
	F("[%s]\n", "bar");
	F("[%.5s]\n", "foo");
	F("[%.2s]\n", "foo");
	F("[%c]\n", 'a');
	F("[%d]\n", 10);
	F("[%d]\n", -12345);
	F("[%d, %d]\n", 123, -12345);
	F("[%d]\n", INT_MIN);
	F("[%d]\n", INT_MAX);
	F("[%10.0d]\n", 0);
	F("[%10.5d]\n", 123);
	F("[%010d]\n", 123);
	F("[%-10.5d]\n", 123);
	F("[%*d]\n", 5, 123);
	F("[%*.*d]\n", 10, 5, 234);
	F("[%%]\n");
	F("[%u]\n", 10);
	F("[%u]\n", -1);
	F("[%x]\n", 1);
	F("[%x]\n", 123);
	F("[%x]\n", INT_MAX / 2);
	printf("res is %d\n", res);

	// int x = 42;
	// F("[%p]\n", &x);
	int x = 123;
	// F("[%p]\n", &x);
	
	
	return (0);
}

#endif // TEST