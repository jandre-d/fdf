/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   height_color.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:55:46 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 15:59:51 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "height_color.h"

static void	get_color(int32_t delta, int32_t current, t_color *color)
{
	t_color	from;
	t_color	to;
	double	percent;

	from.r = 0;
	from.g = 153;
	from.b = 255;
	to.r = 255;
	to.g = 255;
	to.b = 0;
	percent = ((current == delta) ? 1.0 : (double)current / (double)delta);
	color->r = (1 - percent) * from.r + percent * to.r;
	color->g = (1 - percent) * from.g + percent * to.g;
	color->b = (1 - percent) * from.b + percent * to.b;
}

static void	get_bounds(int32_t *max, int32_t *min, t_object_elem *object)
{
	uint32_t off_x;
	uint32_t off_y;

	off_y = 0;
	while (off_y < object->size_y)
	{
		off_x = 0;
		while (off_x < object->size_x)
		{
			if (object->vectors[off_y][off_x].r_loc.z > *max)
				*max = object->vectors[off_y][off_x].r_loc.z;
			if (object->vectors[off_y][off_x].r_loc.z < *min)
				*min = object->vectors[off_y][off_x].r_loc.z;
			off_x++;
		}
		off_y++;
	}
}

void		set_color_based_on_height(t_object_elem *object)
{
	int32_t		max;
	int32_t		min;
	uint32_t	off_x;
	uint32_t	off_y;

	min = 0;
	max = 0;
	get_bounds(&max, &min, object);
	off_y = 0;
	while (off_y < object->size_y)
	{
		off_x = 0;
		while (off_x < object->size_x)
		{
			get_color(max - min, object->vectors[off_y][off_x].r_loc.z,
				&object->vectors[off_y][off_x].r_loc.color);
			off_x++;
		}
		off_y++;
	}
}
