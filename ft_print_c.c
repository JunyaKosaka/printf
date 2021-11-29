/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:09:25 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/29 19:48:21 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_spec *spc, va_list *ap)
{
	int		ret;
	char	c;

	ret = 0;
	c = va_arg(*ap, int);
	while (!(spc->left_align) && spc->min_width > 1)
	{
		ret += ft_putchar(' ');
		spc->min_width--;
	}
	ret += ft_putchar(c);
	while (spc->min_width > 1)
	{
		ret += ft_putchar(' ');
		spc->min_width--;
	}
	return (ret);
}
