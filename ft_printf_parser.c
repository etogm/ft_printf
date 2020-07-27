/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanette <ljanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 21:46:56 by ljanette          #+#    #+#             */
/*   Updated: 2020/07/27 16:10:34 by ljanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_size(char *fmt, int i, int *num, int *width_flag, va_list arg)
{
	if (ft_isdigit(fmt[i]))
	{
		*num = 0;
		while (ft_isdigit(fmt[i]))
		{
			*num = *num * 10 + (fmt[i] - '0');
			i++;
		}
	}
	else if (fmt[i] == '*')
	{
		*num = va_arg(arg, int);
		i++;
		if (*num < 0 && width_flag != NULL)
		{
			*width_flag = 1;
			*num = -*num;
		}
		else if (*num < 0 && width_flag == NULL)
			*num = -1;
	}
	else
		*num = 0;
	return (i);
}

t_info		*info_init()
{
	t_info	*info;

	info = (t_info*)malloc(sizeof(t_info));
	info->type = '!';
	info->accuracy = -1;
	info->width = 0;
	info->width_flag = 0;
	info->zero_flag = 0;
	return (info);
}

int			get_info(char *fmt, int i, t_info **main_info, va_list arg)
{
	t_info *info;

	info = info_init();
	while (fmt[i] == '0' || fmt[i] == '-')
	{
		if (fmt[i] == '-')
			info->width_flag = 1;
		if (fmt[i] == '0')
			info->zero_flag = 1;
		i++;
	}
	i = get_size(fmt, i, &info->width, &info->width_flag, arg);
	if (fmt[i] == '.')
		i = get_size(fmt, ++i, &info->accuracy, NULL, arg);
	if (istype(fmt[i]))
		info->type = fmt[i++];
	*main_info = info;
	return (i);
}