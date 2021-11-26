/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:35:55 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/27 00:33:58 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	putxint(unsigned int num, int padding)
{
	int	ret;

	ret = 0;
	while (padding-- > 0)
		ret += ft_putchar('0');
	if (num / 16)
		ret += putxint((num / 16), 0);
	ret += ft_putchar("0123456789abcdef"[num % 16]);
	return (ret);
}

static int	print_x_core(t_spec *spc, unsigned int u, int u_len, int padding)
{
	int	ret;

	ret = 0;
	while (!(spc->has_left) && u_len < spc->min_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	if (spc->precision == 0 && u == 0)
		return (ret);
	ret += putxint(u, padding);
	while (u_len < spc->min_width)
	{
		ret += ft_putchar(' ');
		spc->min_width--;
	}
	return (ret);
}

int	ft_print_x(t_spec *spc, va_list *ap)
{
	int				ret;
	int				u_len;
	int				padding;
	unsigned int	u;

	ret = 0;
	u = va_arg(*ap, unsigned int);
	u_len = ft_get_digits(u, 16);
	if (spc->precision == 0 && u == 0)
		u_len = 0;
	padding = 0;
	if (u_len < spc->precision)
		padding = spc->precision - u_len;
	u_len += padding;
	ret += print_x_core(spc, u, u_len, padding);
	return (ret);
}
