/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 10:54:03 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:51:14 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*to_return;

	to_return = malloc(size);
	if (to_return != NULL)
		ft_bzero(to_return, size);
	return (to_return);
}
