/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:02:19 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/28 15:51:50 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_s(t_spec *spc, va_list *ap)
{
	int		ret;
	int		min_width;
	int		precision;
	int		s_len;
	char	*str;

	ret = 0;
	min_width = spc->min_width;
	precision = spc->precision;
	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	s_len = ft_strlen(str);
	if (0 <= precision && precision < s_len)
		s_len = precision;
	while (!(spc->has_left) && s_len < min_width)
	{
		ret += ft_putchar(' ');
		min_width--;
	}
	ret += putnstr(str, s_len);
	while (s_len < min_width)
	{
		ret += ft_putchar(' ');
		min_width--;
	}	
	return (ret);
}