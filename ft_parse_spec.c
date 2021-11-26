/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:28:22 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/26 17:48:09 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*parse_flag(t_spec *spc, char **ptr, va_list *ap)
{
	if (**ptr == '-')
	{
		spc->has_left = 1;
		(*ptr)++;
	}
	if (**ptr == '0')
	{
		spc->has_zero = 1;
		(*ptr)++;
	}
	// sharp
	return (*ptr);
}

static char	*parse_min_width(t_spec *spc, char **ptr, va_list *ap)
{
	if (ft_isdigit(**ptr))
	{
		spc->min_width = ft_atoi(*ptr);
		*ptr += ft_get_digits(spc->min_width);
	}
	else if (**ptr == '*')
	{
		spc->min_width = va_arg(*ap, int);
		(*ptr)++;
	}
	return (*ptr);
}

static char	*parse_dot(t_spec *spc, char **ptr, va_list *ap)
{
	if (**ptr == '.')
	{
		(*ptr)++;  // handle *
		if (ft_isdigit(**ptr))
		{
			spc->precision = ft_atoi(*ptr);
			*ptr += ft_get_digits(spc->precision);
		}
	}
	return (*ptr);
}

char *ft_parse_spec(t_spec *spc, char *ptr, va_list *ap)
{
	ptr++; // %の分
	ptr = parse_flag(spc, &ptr, ap);
	ptr = parse_min_width(spc, &ptr, ap);
	ptr = parse_dot(spc, &ptr, ap);
	if (spc->has_left || spc->precision >= 0)
		spc->has_zero = 0;
	if (ft_strchr("cspdiuxX%", *ptr))  // handle %
	{
		spc->c = *ptr;
		return (++ptr);
	}
	return (ptr);
}