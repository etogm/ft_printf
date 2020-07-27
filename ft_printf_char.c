/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanette <ljanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:12:29 by ljanette          #+#    #+#             */
/*   Updated: 2020/07/27 14:40:08 by ljanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_s(t_info *info, va_list arg)
{
	char	*str;
	int		length;
	int		size;

	size = 0;
	str = va_arg(arg, char*);
	if (str == NULL)
		str = "(null)";
	if (info->accuracy == -1 || (ft_strlen(str) < info->accuracy))
		length = ft_strlen(str);
	else
		length = info->accuracy;
	if (info->width > 0 && !info->width_flag)
		size += ft_putspace(length, info->width, ' ');
	length = 0;
	while (str[length] && (length < info->accuracy || info->accuracy == -1))
		size += ft_putchar(str[length++]);
	if (info->width > 0 && info->width_flag)
		size += ft_putspace(length, info->width, ' ');
	return (size);
}

int			print_char_pre(t_info *info, char *sign, int *length)
{
	int		size;
	int		len_tmp;
	char	c;

	size = 0;
	c = (info->zero_flag && info->type == '%') ? '0' : ' ';
	len_tmp = *length;
	len_tmp += (sign) ? ft_strlen(sign) : 0;
	size += (sign && c == '0') ? ft_putstr(sign) : 0;
	if (info->width > 0 && !info->width_flag)
		size += ft_putspace(len_tmp, info->width, c);
	size += (sign && c == ' ') ? ft_putstr(sign) : 0;
	return (size);
}

int			ft_printf_c(t_info *info, va_list arg)
{
	char	*sign;
	int		length;
	int		size;

	size = 0;
	sign = "";
	length = 1;
	info->zero_flag = 0;
	size += print_char_pre(info, sign, &length);
	ft_putchar(va_arg(arg, int));
	if (info->width > 0 && info->width_flag)
		size += ft_putspace(length, info->width, ' ');
	return (size);
}

int			ft_printf_precent(t_info *info)
{
	char	*sign;
	int		length;
	int		size;

	size = 0;
	sign = "";
	length = 1;
	size += print_char_pre(info, sign, &length);
	ft_putchar('%');
	if (info->width > 0 && info->width_flag)
		size += ft_putspace(length, info->width, ' ');
	return (size);
}
