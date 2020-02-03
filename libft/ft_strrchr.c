/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:35:45 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/04 12:11:14 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*prev;

	prev = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			prev = (char *)s;
		}
		s++;
	}
	if (c == '\0')
	{
		prev = (char *)s;
	}
	return (prev);
}
