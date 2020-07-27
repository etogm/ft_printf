/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanette <ljanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:05:14 by ljanette          #+#    #+#             */
/*   Updated: 2020/07/27 14:35:24 by ljanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_word(t_info *info, va_list arg)
{
	int size;

	size = 0;
	if (info->type == 'c')
		size += ft_printf_c(info, arg);
	else if (info->type == 's')
		size += ft_printf_s(info, arg);
	else if (info->type == 'd' || info->type == 'i')
		size += ft_printf_num(info, arg, 10, 1);
	else if (info->type == 'u')
		size += ft_printf_num(info, arg, 10, 0);
	else if (info->type == 'x' || info->type == 'X')
		size += ft_printf_num(info, arg, 16, 0);
	else if (info->type == 'p')
		size += ft_printf_num(info, arg, 16, 0); // XXXX
	else if (info->type == '%')
		size += ft_printf_precent(info);
	return (size);
}

int			ft_dprintf(char *fmt, va_list arg)
{
	t_info	*info;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i = get_info(fmt, ++i, &info, arg);
			size += print_word(info, arg);
			//printf("info:\nwidth-flag: %d\nwidth: %d\naccuracy: %d\ntype: %c\n", info->width_flag, info->width, info->accuracy, info->type);
			free(info);
		}
		else if (fmt[i])
			size += ft_putchar(fmt[i++]);
	}
	return (size);
}

int			ft_printf(const char *format, ...)
{
	char	*fmt;
	int		size;
	va_list	arg;

	size = 0;
	fmt = ft_strdup(format);
	va_start(arg, format);
	size = ft_dprintf(fmt, arg);
	va_end(arg);
	free(fmt);
	return (size);
}
