/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 05:46:57 by jandre-d       #+#    #+#                */
/*   Updated: 2019/01/12 10:22:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *prev;
	t_list *next;

	next = lst;
	while (next != NULL)
	{
		prev = next;
		next = next->next;
		f(prev);
	}
}
