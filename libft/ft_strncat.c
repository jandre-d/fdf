/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:41:54 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/04 12:10:17 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*to_return;

	i = 0;
	to_return = s1;
	while (*s1)
	{
		s1++;
	}
	while (s2[i] && n > 0)
	{
		n--;
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (to_return);
}
