/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:35:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/29 20:46:55 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_x(t_ull num, int padding)
{
	int	ret;

	ret = 0;
	while (padding-- > 0)
		ret += ft_putchar('0');
	if (num / 16)
		ret += put_x((num / 16), 0);
	ret += ft_putchar("0123456789abcdef"[num % 16]);
	return (ret);
}

static int	print_p_core(t_spec *spc, t_ull p, int p_len, int padding)
{
	int	ret;

	ret = 0;
	while (!(spc->left_align) && p_len < spc->min_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	if (spc->precision == 0 && p == 0)
		return (ret);
	while (!(spc->left_align) && p_len < spc->min_width)
	{
		ret += ft_putchar(' ');
		spc->min_width--;
	}
	ret += ft_putstr("0x");
	ret += put_x(p, padding);
	while (p_len < spc->min_width)
	{
		ret += ft_putchar(' ');
		spc->min_width--;
	}
	return (ret);
}

int	ft_print_p(t_spec *spc, va_list ap)
{
	int		ret;
	t_ull	p;
	int		p_len;
	int		padding;

	ret = 0;
	p = (t_ull)va_arg(ap, void *);
	p_len = ft_get_digits_u(p, 16) + 2;
	padding = 0;
	// printf("\n66:%llu\n", p);
	if (p < 0 && (p_len - 1) < spc->precision)
		padding = spc->precision - (p_len - 1);
	else if (p >= 0 && p_len < spc->precision)
		padding = spc->precision - p_len;
	p_len += padding;
	ret += print_p_core(spc, p, p_len, padding);
	return (ret);
}
