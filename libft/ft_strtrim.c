/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 12:52:17 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:48:28 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	right_offset(char const *str, size_t len)
{
	size_t i;

	i = 0;
	if (len == 0)
		return (0);
	len -= 1;
	while (len > 0 && (str[len] == ' ' || str[len] == '\n' || str[len] == '\t'))
	{
		len -= 1;
		i += 1;
	}
	return (i);
}

static size_t	left_offset(char const *str)
{
	size_t i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		i += 1;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	l_off;
	size_t	r_off;
	size_t	old_len;
	char	*to_return;

	old_len = ft_strlen(s);
	l_off = left_offset(s);
	r_off = right_offset(s + l_off * sizeof(char), old_len - l_off);
	to_return = ft_strnew(old_len - (l_off + r_off));
	if (to_return != NULL)
	{
		ft_memmove(to_return, s + l_off * sizeof(char),
		old_len - l_off - r_off);
		to_return[old_len - r_off - l_off] = '\0';
	}
	return (to_return);
}
