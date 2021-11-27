/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:21:59 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/27 11:27:28 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	putint(int n, int padding)
{
	int			ret;
	long long	num;

	ret = 0;
	num = n;
	if (num < 0)
	{
		ret += ft_putchar('-');
		num *= -1;
	}
	while (padding-- > 0)
		ret += ft_putchar('0');
	if (num / 10)
		ret += putint((int)(num / 10), 0);
	ret += ft_putchar('0' + (num % 10));
	return (ret);
}

static int	print_d_core(t_spec *spc, int d, int d_len, int padding)
{
	int	ret;

	ret = 0;
	if (spc->has_plus && d >= 0)
		spc->min_width--;
	if (spc->has_space && d >= 0)
		spc->min_width--;
	while (!(spc->has_left) && d_len < spc->min_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	if (spc->precision == 0 && d == 0)
		return (ret);
	if (spc->has_plus && d >= 0)
		ret += ft_putchar('+');
	if (spc->has_space && d >= 0)
		ret += ft_putchar(' ');
	ret += putint(d, padding);
	while (d_len < spc->min_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	return (ret);
}

int	ft_print_d(t_spec *spc, va_list *ap)
{
	int		ret;
	int		d;
	int		d_len;
	int		padding;

	ret = 0;
	d = va_arg(*ap, int);
	d_len = ft_get_digits(d, 10);
	if (spc->precision == 0 && d == 0)
		d_len = 0;
	padding = 0;
	if (d < 0 && (d_len - 1) < spc->precision)
		padding = spc->precision - (d_len - 1);
	else if (d >= 0 && d_len < spc->precision)
		padding = spc->precision - d_len;
	d_len += padding;
	ret += print_d_core(spc, d, d_len, padding);
	return (ret);
}
