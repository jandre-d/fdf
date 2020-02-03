/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 16:09:48 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:48:31 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*to_return;
	int		len;

	len = size(n) - 1;
	to_return = ft_strnew(len + 1);
	if (to_return == NULL)
		return (NULL);
	to_return[len + 1] = '\0';
	if (n < 0)
		to_return[0] = '-';
	if (n == -2147483648)
	{
		n = 147483648;
		to_return[1] = '2';
	}
	else if (n < 0)
		n = -n;
	while (n >= 10)
	{
		to_return[len] = n % 10 + '0';
		len--;
		n /= 10;
	}
	to_return[len] = n + '0';
	return (to_return);
}
