/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:21:59 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/26 00:07:32 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	putint(int n, int padding)
{
	int		ret;
	long	num;

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
		ret += putint(num / 10, 0);
	ret += ft_putchar('0' + (num % 10));
	return (ret);
}

int	ft_print_d(t_arg *arg, va_list *ap)
{
	int		ret;
	int		d_len;
	int		padding;
	int		d;

	ret = 0;
	d = va_arg(*ap, int);
	d_len = ft_get_digits(d);
	if (arg->precision == 0 && d == 0)
		d_len = 0;
	padding = 0;
	if (d < 0 && (d_len - 1) < arg->precision)
		padding = arg->precision - (d_len - 1);
	else if (d >= 0 && d_len < arg->precision)
		padding = arg->precision - d_len;
	d_len += padding;
	while (d_len < arg->width)
	{
		ret += ft_putchar(' ');
		arg->width--;
	}
	if (arg->precision == 0 && d == 0)	
		return (ret);
	return (ret + putint(d, padding));
}