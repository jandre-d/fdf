/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 09:20:44 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:38:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "fdf.h"

uint32_t		*image_get_data_ptr(void *img_ptr);
void			image_push(t_fdf *fdf_ptr);
void			image_set_pixel(uint32_t *img_data, int32_t x, int32_t y,
	uint32_t color);
void			image_clear(uint32_t *img_data);

#endif
