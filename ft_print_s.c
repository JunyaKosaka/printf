/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:02:19 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/29 19:47:19 by jkosaka          ###   ########.fr       */
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
	size_t	s_len;
	char	*str;

	ret = 0;
	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	s_len = ft_strlen(str);
	if (s_len > INT_MAX)
		return (INT_MAX);
	if (0 <= spc->precision && spc->precision < (int)s_len)
		s_len = spc->precision;
	while (!(spc->left_align) && (int)s_len < spc->min_width)
	{
		ret += ft_putchar(' ');
		spc->min_width--;
	}
	ret += putnstr(str, s_len);
	while ((int)s_len < spc->min_width)
	{
		ret += ft_putchar(' ');
		spc->min_width--;
	}
	return (ret);
}
