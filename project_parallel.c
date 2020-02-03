/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   project_parallel.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 13:41:14 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:15:48 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "project_parallel.h"
#include "vector.h"
#include "draw.h"

static void	vector_to_2d_point(t_object_elem *object, t_vector3 *vector,
	t_point *point)
{
	t_vector3 v_mod;

	ft_memcpy(&v_mod, vector, sizeof(t_vector3));
	vector_rotate_x(object->rotation.x * PI_OVER_180, &v_mod);
	vector_rotate_y(object->rotation.y * PI_OVER_180, &v_mod);
	vector_rotate_z(object->rotation.z * PI_OVER_180, &v_mod);
	point->x = v_mod.x + object->a_loc.x + WINDOW_X / 2;
	point->y = v_mod.y + object->a_loc.y + WINDOW_Y / 2;
	ft_memcpy(&point->color, &vector->color, sizeof(t_color));
}

static void	connect(int32_t off_x, int32_t off_y, uint32_t *img,
	t_object_elem *object)
{
	t_point		a;
	t_point		b;
	t_vector3	v_a;
	t_vector3	v_b;

	ft_memcpy(&v_a, &object->vectors[off_y][off_x].r_loc, sizeof(t_vector3));
	vector_to_2d_point(object, &v_a, &a);
	if (off_y != 0)
	{
		ft_memcpy(&v_b, &object->vectors[off_y - 1][off_x].r_loc,
			sizeof(t_vector3));
		vector_to_2d_point(object, &v_b, &b);
		draw_line(&a, &b, img);
	}
	if (off_x != 0)
	{
		ft_memcpy(&v_b, &object->vectors[off_y][off_x - 1].r_loc,
			sizeof(t_vector3));
		vector_to_2d_point(object, &v_b, &b);
		draw_line(&a, &b, img);
	}
}

static void	project_one_parallel(uint32_t *img, t_object_elem *object)
{
	uint32_t off_x;
	uint32_t off_y;

	off_y = 0;
	while (off_y < object->size_y)
	{
		off_x = 0;
		while (off_x < object->size_x)
		{
			connect(off_x, off_y, img, object);
			off_x++;
		}
		off_y++;
	}
}

void		project_parallel(uint32_t *img, t_world *world)
{
	t_object_elem *use_me;

	if (world->only_project_selected_object)
	{
		project_one_parallel(img, world->selected_obj);
	}
	else
	{
		use_me = world->object_list;
		while (use_me != NULL)
		{
			project_one_parallel(img, use_me);
			use_me = use_me->next;
		}
	}
}
