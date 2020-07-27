/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanette <ljanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:56:25 by ljanette          #+#    #+#             */
/*   Updated: 2020/07/27 04:02:21 by ljanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		get_num(t_info *info, va_list arg, int issigned, char **sign)
{
	size_t	num;
	long	num_tmp;

	if (issigned)
	{
		num_tmp = va_arg(arg, int);
		if (num_tmp < 0)
		{
			*sign = "-";
			num = -num_tmp;
		}
		else
			num = num_tmp;
	}
	else
	{
		num = va_arg(arg, unsigned long);
		if (info->type == 'p')
			*sign = "0x";
		else
			*sign = "";
	}
	return (num);
}

char		*get_strnum(t_info *info, va_list arg, int base, int issigned, char **sign)
{
	size_t	num;
	int		length;
	char	*digits;
	char	*buf;

	if (info->type == 'X')
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	num = get_num(info, arg, issigned, sign);
	length = numlen(num, base);
	buf = (char*)malloc((length + 1) * sizeof(char));
	buf[length] = '\0';
	if (num == 0)
		buf[0] = '0';
	while (num != 0)
	{
		buf[length - 1] = digits[num % base];
		num /= base;
		length--;
	}
	return (buf);
}

int			print_pre(t_info *info, char *sign, int len_num)
{
	int		size;
	int		len_main;
	char	c;

	size = 0;
	c = (info->zero_flag && info->accuracy == -1) ? '0' : ' ';
	len_main = (info->accuracy  > len_num && info->width > 0 && !info->width_flag) ? info->accuracy : len_num;
	len_main += (sign) ? ft_strlen(sign) : 0;
	size += (sign && c == '0') ? ft_putstr(sign) : 0;
	if (info->width > 0 && !info->width_flag)
		size += ft_putspace(len_main, info->width, c);
	size += (sign && c == ' ') ? ft_putstr(sign) : 0;
	if (info->accuracy > 0)
		size += ft_putspace(len_num, info->accuracy, '0');
	return (size);
}
/*
	- 00000 123	%08d	0x 00000 123
	_____ - 123	%8d		_____ 0x 123
	__ - 00 123	%8.2d	__ 0x 00 123
*/

int			ft_printf_num(t_info *info, va_list arg, int base, int issigned)
{
	char	*buf;
	char	*sign;
	int		length;
	int		size;
	int		i;

	size = 0;
	sign = "";
	buf = get_strnum(info, arg, base, issigned, &sign);
	length = print_pre(info, sign, (buf[0] != '0' || info->accuracy != 0) ? ft_strlen(buf) : 0);
	size += length;
	i = 0;
	if (buf[0] != '0' || info->accuracy != 0)
	{
		while (buf[i])
		{
			size += ft_putchar(buf[i++]);
			length++;
		}
	}
	if (info->width > 0 && info->width_flag)
		size += ft_putspace(length, info->width, ' ');
	free(buf);
	return (size);
}
