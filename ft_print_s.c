/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:02:19 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/29 01:31:17 by jkosaka          ###   ########.fr       */
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
	int		precision;
	int		s_len;
	char	*str;

	ret = 0;
	precision = spc->precision;
	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	s_len = ft_strlen(str);
	if (0 <= precision && precision < s_len)
		s_len = precision;
	while (!(spc->left_align) && s_len < spc->min_width)
	{
		ret += ft_putchar(' ');
		spc->min_width--;
	}
	ret += putnstr(str, s_len);
	while (s_len < spc->min_width)
	{
		ret += ft_putchar(' ');
		spc->min_width--;
	}	
	return (ret);
}
