/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:17:29 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/27 00:10:52 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_get_digits(int x, int base)
{
	int		ret;
	long	num;

	ret = 1;
	num = x;
	if (num < 0)
	{
		num *= -1;
		ret++;
	}
	if (num / base)
		ret += ft_get_digits(num / base, base);
	return (ret);
}