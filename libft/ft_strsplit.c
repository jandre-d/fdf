/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 13:36:47 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:48:28 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_array_len(char *str, char c)
{
	size_t i;

	if (!*str)
		return (0);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			i++;
		while (*str && *str != c)
			str++;
	}
	return (i);
}

static size_t	get_next_word_len(char *from, char c)
{
	size_t i;

	i = 0;
	while (*from && *from != c)
	{
		i++;
		from++;
	}
	return (i);
}

static char		*set_next_word(char **from, char c)
{
	char	*to_return;
	size_t	i;
	size_t	len;

	len = get_next_word_len(*from, c);
	to_return = ft_strnew(len);
	if (to_return == NULL)
		return (NULL);
	i = 0;
	while ((*from)[i] && (*from)[i] != c)
	{
		to_return[i] = (*from)[i];
		i++;
	}
	*from += i;
	return (to_return);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**to_return;
	size_t	array_len;

	array_len = get_array_len((char *)s, c);
	to_return = (char **)ft_memalloc((array_len + 1) * sizeof(char *));
	if (to_return == NULL)
		return (NULL);
	to_return[array_len] = 0;
	array_len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			to_return[array_len] = set_next_word((char **)(&s), c);
			if (to_return[array_len] == NULL)
				return (NULL);
			array_len++;
		}
	}
	return (to_return);
}
