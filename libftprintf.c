/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:42:38 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/25 21:03:22 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init_arg(t_arg *arg)
{
	arg->s = 0;
	arg->width = -1;
	arg->precision = -1;
}

char *read_specifier(t_arg *arg, char *ptr)
{
	ptr++; // %の分
	while (*ptr)
	{
		if (ft_isdigit(*ptr))
		{
			arg->width = ft_atoi(ptr);
			ptr += ft_get_digits(arg->width);
		}
		if (*ptr == '.')
		{
			ptr++;
			if (ft_isdigit(*ptr))
			{
				arg->precision = ft_atoi(ptr);
				ptr += ft_get_digits(arg->precision);
			}
		}
		if (ft_strchr("cspdiuxX%", *ptr))  // %対応
		{
			arg->s = *ptr;
			return (++ptr);
		}
		ptr++;
	}
	return (ptr);
}


static int	print_arg(t_arg *arg, va_list *ap)
{
	if (arg->s == 'c')
		return (0); // todo
	if (arg->s == 's')
		return (ft_print_s(arg, ap)); // todo
	if (arg->s == 'p')
		return (0); // todo
	if (arg->s == 'd')
		return (0); // todo
	if (arg->s == 'i')
		return (0); // todo
	if (arg->s == 'u')
		return (0); // todo
	if (arg->s == 'x')
		return (0); // todo
	if (arg->s == 'X')
		return (0); // todo
	return (0);
}

static int	ft_printf_core(char *ptr, va_list ap)
{
	int		ret;
	t_arg	arg;

	ret = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			init_arg(&arg);	
			ptr = read_specifier(&arg, ptr);
			ret += print_arg(&arg, &ap);
			continue ;
		}
		ret += ft_putchar(*ptr);
		ptr++;
	}
	return (ret);
}

int	ft_printf(const char * restrict format, ...)
{
	char	*ptr;
	int		ret;
	va_list	ap;

	ret = 0;
	ptr = (char *)format;
	if (!ptr)
		return (0);
	va_start(ap, format);
	ret += ft_printf_core(ptr, ap);
	va_end(ap);
	return (ret);
}
