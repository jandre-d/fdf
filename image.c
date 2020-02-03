/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 09:21:54 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 15:58:05 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "minilibx_macos/mlx.h"

uint32_t		*image_get_data_ptr(void *img_ptr)
{
	int32_t trash;

	return ((uint32_t *)mlx_get_data_addr(img_ptr,
		&trash, &trash, &trash));
}

void			image_push(t_fdf *fdf_ptr)
{
	mlx_put_image_to_window(
		fdf_ptr->mlx_ptr, fdf_ptr->win_ptr, fdf_ptr->img_ptr, 0, 0);
}

void			image_set_pixel(uint32_t *img_data, int32_t x, int32_t y,
	uint32_t color)
{
	if (y < WINDOW_Y && x < WINDOW_X && y > 0 && x > 0)
		img_data[(y * WINDOW_X) + x] = color;
}

void			image_clear(uint32_t *img_data)
{
	ft_memset((void *)img_data, 0, BPP * WINDOW_X * WINDOW_Y);
}
