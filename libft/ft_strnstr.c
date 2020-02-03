/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:11:16 by jandre-d       #+#    #+#                */
/*   Updated: 2019/01/16 12:13:50 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t search_off;

	i = 0;
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i < len)
	{
		search_off = 0;
		while (haystack[i + search_off] == needle[search_off] &&
			i + search_off < len)
		{
			search_off++;
			if (needle[search_off] == '\0')
			{
				return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
