/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 05:52:24 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/04 12:02:20 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *to_return;
	t_list *use;

	use = f(lst);
	if (use == NULL)
		return (NULL);
	to_return = use;
	lst = lst->next;
	while (lst)
	{
		use->next = f(lst);
		if (use->next == NULL)
			return (NULL);
		use = use->next;
		lst = lst->next;
	}
	return (to_return);
}
