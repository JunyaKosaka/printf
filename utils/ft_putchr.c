/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:17:24 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/25 18:17:58 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_putchar(char c)
{
	unsigned char	s;

	s = (unsigned char)c;
	return (write(1, &s, 1));
}