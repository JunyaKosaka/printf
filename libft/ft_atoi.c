/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:43:00 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/27 02:12:12 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_over(long n, int m)
{
	return (n >= (INT_MAX - m) / 10);
}

static int	is_space(int c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

int	ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	sign = 1;
	ret = 0;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = 44 - *str;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (is_over(ret, *str - '0'))
		{
			if (sign > 0)
				return (-1);
			else
				return (0);
		}
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * sign);
}

// #include <stdio.h>
// #include <libc.h>

// int	main(void)
// {
// 	int		i = -1;
// 	char	s[10][30] = {"123abc", " +92233720368547", "-2147483648\n"};
// 	s[0] = to_string(2147483648)
// 	while (++i < 3)
// 	{
// 		if (atoi(s[i]) != ft_atoi(s[i]))
// 			printf("NG\n");
// 		printf("%d\n", ft_atoi(s[i]));
// 	}
// 	printf("Done\n");
// 	return (0);
// }
