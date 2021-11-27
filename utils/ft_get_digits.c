/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:17:29 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/27 17:16:47 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_get_digits(long num, int base)
{
	int		ret;

	ret = 1;
	if (num < 0) // long min と unsigned long 対応
	{
		num *= -1;
		ret++;
	}
	if (num / base)
		ret += ft_get_digits(num / base, base);
	return (ret);
}
