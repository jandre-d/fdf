/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_input_mouse.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 15:41:41 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:12:02 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "user_input_mouse.h"
#include "image.h"
#include "object_movement.h"
#include "project_parallel.h"

int	mouse_press(int button, int x, int y, void *fdf_var)
{
	t_fdf *fdf_ptr;

	fdf_ptr = (t_fdf *)fdf_var;
	if (button == 1)
	{
		fdf_ptr->user_control.mouse1_down = TRUE;
	}
	if (button == 4)
	{
		obj_scale(0.9, 0.9, 0.9, fdf_ptr->world.selected_obj);
	}
	if (button == 5)
	{
		obj_scale(1.1, 1.1, 1.1, fdf_ptr->world.selected_obj);
	}
	image_clear(image_get_data_ptr(fdf_ptr->img_ptr));
	project_parallel(fdf_ptr->img_data_ptr, &fdf_ptr->world);
	image_push(fdf_ptr);
	return (0);
}

int	mouse_release(int button, int x, int y, void *fdf_var)
{
	t_fdf *fdf_ptr;

	fdf_ptr = (t_fdf *)fdf_var;
	if (button == 1)
	{
		fdf_ptr->user_control.mouse1_down = FALSE;
	}
	return (0);
}

int	mouse_move(int x, int y, void *fdf_var)
{
	t_fdf *fdf_ptr;

	fdf_ptr = (t_fdf *)fdf_var;
	if (fdf_ptr->user_control.mouse1_down == TRUE &&
		(fdf_ptr->world.projection_type == PROJECTION_PARALLEL ||
			fdf_ptr->user_control.ctrl_down == TRUE))
	{
		if (fdf_ptr->user_control.mouse1_down == TRUE &&
			fdf_ptr->world.projection_type == PROJECTION_PARALLEL &&
				fdf_ptr->user_control.ctrl_down == FALSE)
			obj_rot(-(y - fdf_ptr->user_control.prev_y),
				(x - fdf_ptr->user_control.prev_x), 0,
					fdf_ptr->world.selected_obj);
		else
			obj_move((x - fdf_ptr->user_control.prev_x),
				(y - fdf_ptr->user_control.prev_y), 0,
					fdf_ptr->world.selected_obj);
		image_clear(image_get_data_ptr(fdf_ptr->img_ptr));
		project_parallel(fdf_ptr->img_data_ptr, &fdf_ptr->world);
		image_push(fdf_ptr);
	}
	fdf_ptr->user_control.prev_x = x;
	fdf_ptr->user_control.prev_y = y;
	return (0);
}
