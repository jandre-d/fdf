/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_input_keyboard.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 15:41:43 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 12:07:24 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "user_input_keyboard.h"
#include "world.h"
#include "image.h"
#include "object_movement.h"
#include "project_parallel.h"
#include <stdlib.h>

static void	key_press_extend(int key, t_fdf *fdf_ptr)
{
	if (key == 49)
	{
		fdf_ptr->world.only_project_selected_object =
			fdf_ptr->world.only_project_selected_object == TRUE ? FALSE : TRUE;
	}
	if (key == 256)
		fdf_ptr->user_control.ctrl_down = TRUE;
	if (key == 48)
	{
		wold_select_next_object(&fdf_ptr->world);
		fdf_ptr->world.projection_type = PROJECTION_PARALLEL;
	}
	if (key == 36 && fdf_ptr->world.projection_type == PROJECTION_PARALLEL)
	{
		obj_to_iso(fdf_ptr->world.selected_obj);
		fdf_ptr->world.projection_type = PROJECTION_ISO;
	}
	else if (key == 36)
		fdf_ptr->world.projection_type = PROJECTION_PARALLEL;
}

int			key_press(int key, void *fdf_var)
{
	t_fdf			*fdf_ptr;
	t_object_elem	*obj;

	fdf_ptr = (t_fdf *)fdf_var;
	obj = fdf_ptr->world.selected_obj;
	if (key == 53)
		exit(0);
	if (fdf_ptr->world.projection_type == PROJECTION_ISO)
	{
		obj_rot(((key == 15) ? 90 : 0), ((key == 17) ? 90 : 0),
			((key == 16) ? 90 : 0), obj);
		obj_rot(((key == 3) ? -90 : 0), ((key == 5) ? -90 : 0),
			((key == 4) ? -90 : 0), obj);
	}
	obj_scale(((key == 32) ? 1.1 : 1), ((key == 34) ? 1.1 : 1),
		((key == 31) ? 1.1 : 1), obj);
	obj_scale(((key == 38) ? 0.9 : 1), ((key == 40) ? 0.9 : 1),
		((key == 37) ? .9 : 1), obj);
	key_press_extend(key, fdf_ptr);
	image_clear(image_get_data_ptr(fdf_ptr->img_ptr));
	project_parallel(fdf_ptr->img_data_ptr, &fdf_ptr->world);
	image_push(fdf_ptr);
	return (0);
}

int			key_release(int key, void *fdf_var)
{
	t_fdf *fdf_ptr;

	fdf_ptr = (t_fdf *)fdf_var;
	if (key == 256)
	{
		fdf_ptr->user_control.ctrl_down = FALSE;
	}
	return (0);
}
