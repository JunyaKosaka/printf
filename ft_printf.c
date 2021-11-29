/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:42:38 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/29 22:12:18 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_spec(t_spec *spc, va_list ap)
{
	if (spc->c == 'c')
		return (ft_print_c(spc, ap));
	if (spc->c == 's')
		return (ft_print_s(spc, ap));
	if (spc->c == 'p')
		return (ft_print_p(spc, ap));
	if (spc->c == 'd')
		return (ft_print_d(spc, ap));
	if (spc->c == 'i')
		return (ft_print_d(spc, ap));
	if (spc->c == 'u')
		return (ft_print_u(spc, ap));
	if (spc->c == 'x')
		return (ft_print_x(spc, ap));
	if (spc->c == 'X')
		return (ft_print_lx(spc, ap));
	return (0);
}

static int	convert_to_int(size_t n)
{
	if (n == INT_MAX)
		return (-1);
	return ((int)n);
}

static int	ft_printf_core(char *ptr, va_list ap)
{
	size_t	ret;
	size_t	temp;
	t_spec	spc;

	ret = 0;
	while (*ptr && ret < INT_MAX)
	{
		if (*ptr == '%' && *(ptr + 1) == '%')
			ptr++;
		else if (*ptr == '%')
		{
			ptr = ft_parse_spec(&spc, ptr, ap);
			if (!ptr)
				return (-1);
			temp = print_spec(&spc, ap);
			if (INT_MAX - ret <= temp)
				return (-1);
			ret += temp;
			continue ;
		}
		ret += ft_putchar(*ptr);
		ptr++;
	}
	return (convert_to_int(ret));
}

int	ft_printf(const char *format, ...)
{
	char	*ptr;
	int		ret;
	va_list	ap;

	ptr = (char *)format;
	va_start(ap, format);
	ret = ft_printf_core(ptr, ap);
	va_end(ap);
	return (ret);
}
