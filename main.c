/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:08:07 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/26 00:08:00 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#ifdef TEST

#include <stdio.h>

#ifdef FT_PRINTF
#define F(...)\
ft_printf(__VA_ARGS__)
#else
#define F(...)\
printf(__VA_ARGS__)
#endif

int	main(void)
{
	F("[foo]\n");
	F("[%s]\n", "bar");
	F("[%.5s]\n", "foo");
	F("[%.2s]\n", "foo");
	F("[%c]\n", 'a');
	F("[%d]\n", 10);
	F("[%d]\n", -12345);
	F("[%10.0d]\n", 0);
	return (0);
}

#endif // TEST