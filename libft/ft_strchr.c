/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:29:14 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/04 12:08:40 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	while (s[i])
	{
		i++;
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
	}
	return (NULL);
}
