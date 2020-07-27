/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanette <ljanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:58:05 by ljanette          #+#    #+#             */
/*   Updated: 2020/07/26 20:28:00 by ljanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (*(src + i) && i + 1 < size)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (size > 0)
		*(dst + i) = '\0';
	while (*(src + i))
		i++;
	return (i);
}

int		ft_strdup_strlen(const char* s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s)
{
	int		size;
	char	*output;

	size = ft_strdup_strlen(s);
	if (!s || !(output = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strlcpy(output, s, size + 1);
	return (output);
}
