/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:35:55 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/29 01:31:17 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_lx(unsigned int num, int padding)
{
	int	ret;

	ret = 0;
	while (padding-- > 0)
		ret += ft_putchar('0');
	if (num / 16)
		ret += put_lx((num / 16), 0);
	ret += ft_putchar("0123456789ABCDEF"[num % 16]);
	return (ret);
}

static int	print_lx_core(t_spec *spc, unsigned int u, int u_len, int padding)
{
	int	ret;

	ret = 0;
	while (!(spc->left_align) && u_len < spc->min_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	if (spc->precision == 0 && u == 0)
		return (ret);
	if (spc->has_sharp)
		ret += ft_putstr("0X");
	ret += put_lx(u, padding);
	while (u_len < spc->min_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	return (ret);
}

int	ft_print_lx(t_spec *spc, va_list *ap)
{
	int				ret;
	int				u_len;
	int				padding;
	unsigned int	u;

	ret = 0;
	u = va_arg(*ap, unsigned int);
	u_len = ft_get_digits(u, 16);
	if (spc->has_sharp && u)
		u_len += 2;
	if (!u)
		spc->has_sharp = 0;
	if (spc->precision == 0 && u == 0)
		u_len = 0;
	padding = 0;
	if (u_len < spc->precision)
		padding = spc->precision - u_len;
	u_len += padding;
	ret += print_lx_core(spc, u, u_len, padding);
	return (ret);
}
