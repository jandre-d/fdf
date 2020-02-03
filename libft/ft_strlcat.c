/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:45:11 by jandre-d       #+#    #+#                */
/*   Updated: 2019/01/16 15:50:00 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len_src;

	i = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size < i)
		i = size;
	if (i == size)
		return (len_src + size);
	if (len_src >= size - i)
	{
		ft_strncat(dst, src, size - i - 1);
		dst[size - 1] = '\0';
	}
	else
		ft_strncat(dst, src, len_src + 1);
	return (len_src + i);
}
