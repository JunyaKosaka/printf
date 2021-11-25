/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:09:25 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/25 23:21:43 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_c(t_arg *arg, va_list *ap)
{
	int		ret;
	int		width;
	char	c;

	ret = 0;
	c = va_arg(*ap, int); // intで良いか確認
	while (width > 1)
	{
		ret += ft_putchar(' ');
		width--;
	}
	return (ret + ft_putchar(c));
}