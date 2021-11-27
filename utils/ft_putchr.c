/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:17:24 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/27 20:25:12 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_putchar(char c)
{
	unsigned char	s;

	s = (unsigned char)c;
	return (write(1, &s, 1));
}

int	ft_putspace(t_spec *spc)
{
	if (spc->has_zero)
		return (ft_putchar('0'));
	else
		return (ft_putchar(' '));
}

int	ft_putstr(char *s)
{
	int	ret;
	
	ret = 0;
	while (*s)
	{
		ret += ft_putchar(*s);
		s++;
	}
	return (ret);
}
