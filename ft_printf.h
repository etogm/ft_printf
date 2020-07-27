/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanette <ljanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:03:34 by ljanette          #+#    #+#             */
/*   Updated: 2020/07/27 13:47:38 by ljanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#  include <stdio.h> //123

typedef struct s_info
{
	int width_flag;
	int zero_flag;
	int width;
	int accuracy;
	char type;
} t_info;

int		ft_putchar(char c);
int		ft_putstr(char* s);
int		ft_strlen(char* s);

int		ft_putspace(int length, int width, char c);
int		numlen(size_t n, int base);
int		istype(char c);
int		ft_isdigit(char c);
int		get_info(char *fmt, int i, t_info **main_info, va_list arg);

int		ft_printf_s(t_info *info, va_list arg);
int		ft_printf_c(t_info *info, va_list arg);
int		ft_printf_num(t_info *info, va_list arg, int base, int issigned);
int		ft_printf_precent(t_info *info);

char	*ft_strdup(const char *s);

int		ft_printf(const char *, ...);

#endif