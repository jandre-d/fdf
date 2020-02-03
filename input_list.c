/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 17:02:32 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:51:51 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input_list.h"
#include "input.h"

void	free_split(char **split)
{
	char **init;

	init = split;
	while (split != NULL && *split != NULL)
	{
		ft_memdel((void **)&(*split));
		split += 1;
	}
	ft_memdel((void **)&init);
}

void	input_list_add_point_to_line(t_input_list_point *add,
t_input_list_line *to)
{
	t_input_list_point *use_me;

	if (to->point_list == NULL)
	{
		to->point_list = add;
	}
	else
	{
		use_me = to->point_list;
		while (use_me->next != NULL)
		{
			use_me = use_me->next;
		}
		use_me->next = add;
	}
}

void	input_list_add_line_to_list(t_input_list_line *add,
t_input_list_lines *to)
{
	t_input_list_line *use_me;

	if (to->line_list == NULL)
	{
		to->line_list = add;
	}
	else
	{
		use_me = to->line_list;
		while (use_me->next != NULL)
		{
			use_me = use_me->next;
		}
		use_me->next = add;
	}
}
