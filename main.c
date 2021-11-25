/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:08:07 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/25 15:08:33 by jkosaka          ###   ########.fr       */
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
	F("hoge\n");
	return (0);
}

#endif // TEST