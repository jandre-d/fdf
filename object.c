/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/02 10:46:06 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:56:03 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static t_object_elem	*vector_array_alloc(t_input *input)
{
	t_object_elem	*to_return;
	uint32_t		i;

	i = 0;
	if (input->heightmap_size_y == 0 || input->heightmap_size_x == 0 ||
	input->list == NULL || input->list->line_list == NULL ||
	input->list->line_list->point_list == NULL)
		return (NULL);
	to_return = NEW(t_object_elem);
	if (to_return == NULL)
		return (NULL);
	to_return->size_y = input->heightmap_size_y;
	to_return->size_x = input->heightmap_size_x;
	to_return->vectors =
		ft_memalloc(to_return->size_y * sizeof(t_object_point *));
	if (to_return->vectors == NULL)
		return (NULL);
	while (i < to_return->size_y)
	{
		if ((to_return->vectors
		[i] = ft_memalloc(to_return->size_x * sizeof(t_object_point))) == NULL)
			return (NULL);
		i++;
	}
	return (to_return);
}

static void				move_input_to(t_input *input, t_object_elem *obj)
{
	t_input_list_line	*use_me_line;
	t_input_list_point	*use_me_point;
	int32_t				offset_x;
	int32_t				offset_y;

	use_me_line = input->list->line_list;
	offset_y = 0;
	while (offset_y < obj->size_y)
	{
		offset_x = 0;
		use_me_point = use_me_line->point_list;
		while (offset_x < obj->size_x)
		{
			obj->vectors[offset_y][offset_x].r_loc.x =
				(offset_x + input->heightmap_size_x / 2 * -1) * POINT_SPACEING;
			obj->vectors[offset_y][offset_x].r_loc.y =
				(offset_y + input->heightmap_size_y / 2 * -1) * POINT_SPACEING;
			obj->vectors[offset_y][offset_x].r_loc.z = use_me_point->height;
			obj->vectors[offset_y][offset_x].r_loc.color.g = 200;
			offset_x++;
			use_me_point = use_me_point->next;
		}
		use_me_line = use_me_line->next;
		offset_y++;
	}
}

void					object_free(t_object_elem *obj)
{
	int32_t				offset_y;

	offset_y = 0;
	while (offset_y < obj->size_y)
	{
		ft_memdel((void**)&(obj->vectors[offset_y]));
		offset_y++;
	}
	ft_memdel((void **)&(obj->vectors));
	ft_memdel((void **)&obj);
}

t_object_elem			*object_elem_from_input(t_input *input)
{
	t_object_elem		*to_return;

	to_return = vector_array_alloc(input);
	if (to_return == NULL)
		return (NULL);
	to_return->size_y = input->heightmap_size_y;
	to_return->size_x = input->heightmap_size_x;
	to_return->filename = input->filename;
	move_input_to(input, to_return);
	return (to_return);
}
