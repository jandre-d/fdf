/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/02 13:29:06 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:13:21 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "object_movement.h"
#include <math.h>
#include "vector.h"

void	obj_scale(double x, double y, double z, t_object_elem *obj)
{
	uint32_t off_x;
	uint32_t off_y;

	off_y = 0;
	while (off_y < obj->size_y)
	{
		off_x = 0;
		while (off_x < obj->size_x)
		{
			obj->vectors[off_y][off_x].r_loc.x *= x;
			obj->vectors[off_y][off_x].r_loc.y *= y;
			obj->vectors[off_y][off_x].r_loc.z *= z;
			off_x++;
		}
		off_y++;
	}
}

void	obj_move(double x, double y, double z, t_object_elem *obj)
{
	obj->a_loc.x += x;
	obj->a_loc.y += y;
	obj->a_loc.z += z;
}

void	obj_rot(double x, double y, double z, t_object_elem *obj)
{
	obj->rotation.x += x;
	obj->rotation.y += y;
	obj->rotation.z += z;
}

void	obj_to_iso(t_object_elem *obj)
{
	obj->rotation.x = 35.264;
	obj->rotation.y = 0;
	obj->rotation.z = 45;
}
