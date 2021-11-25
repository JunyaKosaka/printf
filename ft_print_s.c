/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:02:19 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/25 21:11:51 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	putnstr(char *str, int len)
{
	int	ret;

	ret = 0;
	if (!str)
		return (0);
	while (*str && len > 0)
	{
		ret += ft_putchar(*str);
		str++;
		len--;
	}
	return (ret);
}

int	ft_print_s(t_arg *arg, va_list *ap)
{
	int		ret;
	int		width;
	int		precision;
	int		s_len;
	char	*str;

	ret = 0;
	width = arg->width;
	precision = arg->precision;
	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	s_len = ft_strlen(str);
	if (0 <= precision && precision < s_len)
		s_len = precision;
	while (s_len < width)
	{
		ret += ft_putchar(' ');
		width--;
	}
	return (ret + putnstr(str, s_len));
}