/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 00:31:34 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/01 00:45:55 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(t_spec *spc)
{
	int	ret;
	int	percent_len;
	
	ret = 0;
	percent_len = 1;
	while (!(spc->left_align) && percent_len < spc->min_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	ret += ft_putchar('%');
	while (percent_len < spc->min_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	return (ret);
}
