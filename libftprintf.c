/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:42:38 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/26 23:51:11 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_spec(t_spec *spc, va_list *ap)
{
	if (spc->c == 'c')
		return (ft_print_c(spc, ap));
	if (spc->c == 's')
		return (ft_print_s(spc, ap));
	if (spc->c == 'p')
		return (0);
		// return (ft_print_p(spc, ap));
	if (spc->c == 'd')
		return (ft_print_d(spc, ap));
	if (spc->c == 'i')
		return (0); // todo
	if (spc->c == 'u')
		return (ft_print_u(spc, ap));
	if (spc->c == 'x')
		return (ft_print_x(spc, ap));
	if (spc->c == 'X')
		return (0); // todo
	return (0);
}

static void	init_spc(t_spec *spc)
{
	spc->c = 0;
	spc->min_width = -1;
	spc->precision = -1;
	spc->has_left = 0;
	spc->has_zero = 0;
	spc->has_sharp = 0;
	spc->has_space = 0;
	spc->has_plus = 0;
}

static int	ft_printf_core(char *ptr, va_list ap)
{
	int		ret;
	t_spec	spc;

	ret = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			init_spc(&spc);	
			ptr = ft_parse_spec(&spc, ptr, &ap);
			if (*ptr == '%')
				ret += ft_putchar('%');
			else
				ret += print_spec(&spc, &ap);
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
