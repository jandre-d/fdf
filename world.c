/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   world.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 13:12:49 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:57:55 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "object.h"
#include "input.h"
#include <unistd.h>
#include <fcntl.h>

static void	world_list_add(t_object_elem *obj, t_world *world)
{
	t_object_elem *use_me;

	if (world->object_list == NULL)
		world->object_list = obj;
	else
	{
		use_me = world->object_list;
		while (use_me->next != NULL)
			use_me = use_me->next;
		use_me->next = obj;
	}
	world->selected_obj = obj;
}

int			world_load_object(char *filename, t_world *world)
{
	t_input			*input;
	t_object_elem	*obj;
	int32_t			fd;

	fd = open(filename, O_RDONLY);
	input = input_get(fd);
	if (fd != -1)
		close(fd);
	if (input == NULL)
	{
		ft_putstr("map \"");
		ft_putstr(filename);
		ft_putstr("\" is not formatted correctly\n");
		return (-1);
	}
	obj = object_elem_from_input(input);
	input_free(input);
	if (obj == NULL)
		return (-1);
	world_list_add(obj, world);
	return (0);
}

void		wold_select_next_object(t_world *world)
{
	if (world->selected_obj->next == NULL)
	{
		world->selected_obj = world->object_list;
	}
	else
	{
		world->selected_obj = world->selected_obj->next;
	}
}

int			world_remove_object(char *filename, t_world *world)
{
	t_object_elem *travers_me;
	t_object_elem *free_me;

	if (world->object_list != NULL && filename == world->object_list->filename)
	{
		free_me = world->object_list;
		world->object_list = world->object_list->next;
		object_free(free_me);
	}
	else
	{
		travers_me = world->object_list;
		while (travers_me != NULL && travers_me->next != NULL)
		{
			if (filename == travers_me->next->filename)
			{
				free_me = travers_me->next;
				travers_me->next = travers_me->next->next;
				object_free(free_me);
				return (0);
			}
			travers_me = travers_me->next;
		}
	}
	return (0);
}
