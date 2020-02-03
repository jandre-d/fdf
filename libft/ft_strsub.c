/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 12:30:25 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:48:28 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*to_return;

	i = 0;
	to_return = ft_strnew(len);
	if (to_return == NULL)
		return (NULL);
	to_return[len] = '\0';
	while (i < len)
	{
		to_return[i] = s[start + i];
		i++;
	}
	return (to_return);
}
