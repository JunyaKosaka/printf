/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:35:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/27 18:53:46 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	putxint(unsigned long num, int padding)
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

static int	print_p_core(t_spec *spc, unsigned long p, int p_len, int padding)
{
	int	ret;

	ret = 0;
	while (!(spc->has_left) && p_len < spc->min_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	if (spc->precision == 0 && p == 0)
		return (ret);
	ret += putxint(p, padding);
	while (p_len < spc->min_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	return (ret);
}

int	ft_print_p(t_spec *spc, va_list *ap)
{
	int					ret;
	unsigned long	p;
	int					p_len;
	int					padding;

	ret = 0;
	p = (unsigned long)va_arg(*ap, void *);
	p_len = ft_get_digits(p, 16);
	padding = 0;
	if (p < 0 && (p_len - 1) < spc->precision)
		padding = spc->precision - (p_len - 1);
	else if (p >= 0 && p_len < spc->precision)
		padding = spc->precision - p_len;
	p_len += padding;
	ret += print_p_core(spc, p, p_len, padding);
	return (ret);
}
