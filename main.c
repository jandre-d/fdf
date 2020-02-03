/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 15:12:35 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:52:30 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "world.h"
#include "image.h"
#include "object.h"
#include "height_color.h"
#include "minilibx_macos/mlx.h"
#include "project_parallel.h"
#include "user_input_keyboard.h"
#include "user_input_mouse.h"

static void	fdf_start(t_fdf *fdf_ptr)
{
	fdf_ptr->mlx_ptr = mlx_init();
	fdf_ptr->win_ptr = mlx_new_window(fdf_ptr->mlx_ptr,
		WINDOW_X, WINDOW_Y, "jandre-d fdf");
	fdf_ptr->img_ptr = mlx_new_image(fdf_ptr->mlx_ptr, WINDOW_X, WINDOW_Y);
	fdf_ptr->img_data_ptr = image_get_data_ptr(fdf_ptr->img_ptr);
	mlx_hook(fdf_ptr->win_ptr, 2, 42, key_press, fdf_ptr);
	mlx_hook(fdf_ptr->win_ptr, 3, 42, key_release, fdf_ptr);
	mlx_hook(fdf_ptr->win_ptr, 4, 42, mouse_press, fdf_ptr);
	mlx_hook(fdf_ptr->win_ptr, 5, 42, mouse_release, fdf_ptr);
	mlx_hook(fdf_ptr->win_ptr, 6, 42, mouse_move, fdf_ptr);
	project_parallel(fdf_ptr->img_data_ptr, &fdf_ptr->world);
	image_push(fdf_ptr);
	mlx_loop(fdf_ptr->mlx_ptr);
}

static void	fdf_start1(int argc, char **argv)
{
	t_fdf	*fdf_ptr;
	int32_t	i;

	fdf_ptr = NEW(t_fdf);
	i = 1;
	fdf_ptr->world.projection_type = PROJECTION_PARALLEL;
	while (i < argc)
	{
		if (world_load_object(argv[i], &fdf_ptr->world) != -1)
			set_color_based_on_height(fdf_ptr->world.selected_obj);
		i++;
	}
	if (fdf_ptr->world.selected_obj == NULL)
		return ;
	fdf_start(fdf_ptr);
}

int			main(int argc, char **argv)
{
	fdf_start1(argc, argv);
	return (0);
}
