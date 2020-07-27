/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanette <ljanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:29:16 by ljanette          #+#    #+#             */
/*   Updated: 2020/07/27 01:03:53 by ljanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
			c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int			ft_putspace(int length, int width, char c)
{
	int		size;

	size = 0;
	while (length < width)
	{
		size += ft_putchar(c);
		length++;
	}
	return (size);
}

int			numlen(size_t n, int base)
{
	int		i;

	i = 1;
	while (n / base)
	{
		i++;
		n = n / base;
	}
	return (i);
}
