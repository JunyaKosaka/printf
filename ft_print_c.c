/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:09:25 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/26 15:44:28 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_c(t_spec *spc, va_list *ap)
{
	int		ret;
	int		min_width;
	char	c;

	ret = 0;
	c = va_arg(*ap, int); // intで良いか確認
	while (min_width > 1)
	{
		ret += ft_putchar(' ');
		min_width--;
	}
	return (ret + ft_putchar(c));
}