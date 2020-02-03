/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/16 16:32:46 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:02:49 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "image.h"

static uint32_t	get_color(t_color *from, t_color *to, int32_t delta,
	int32_t current)
{
	double percent;

	percent = ((current == delta) ? 1.0 : (double)current / (double)delta);
	return ((uint8_t)((1 - percent) * from->r + percent * to->r) << 16 |
			(uint8_t)((1 - percent) * from->g + percent * to->g) << 8 |
			(uint8_t)((1 - percent) * from->b + percent * to->b));
}

static void		draw_line_right(t_point *from, t_point *to, uint32_t *img_data)
{
	t_draw_line		draw;

	draw.dx = to->x - from->x;
	draw.dy = to->y - from->y;
	draw.step = draw.dy < 0 ? -1 : 1;
	draw.dy = draw.dy < 0 ? -draw.dy : draw.dy;
	draw.d_dx = 2 * draw.dx;
	draw.d_dy = 2 * draw.dy;
	draw.x = from->x;
	draw.y = from->y;
	draw.difference = draw.d_dy - draw.dx;
	while (draw.x < to->x && draw.x < WINDOW_X && draw.y < WINDOW_Y)
	{
		image_set_pixel(img_data, draw.x, draw.y,
			get_color(&from->color, &to->color, draw.dx, draw.x - from->x));
		if (draw.difference > 0)
		{
			draw.y += draw.step;
			draw.difference -= draw.d_dx;
		}
		draw.difference += draw.d_dy;
		draw.x++;
	}
}

static void		draw_line_down(t_point *from, t_point *to, uint32_t *img_data)
{
	t_draw_line		draw;

	draw.dx = to->x - from->x;
	draw.dy = to->y - from->y;
	draw.step = draw.dx < 0 ? -1 : 1;
	draw.dx = draw.dx < 0 ? -draw.dx : draw.dx;
	draw.d_dx = 2 * draw.dx;
	draw.d_dy = 2 * draw.dy;
	draw.x = from->x;
	draw.y = from->y;
	draw.difference = draw.d_dx - draw.dy;
	while (draw.y < to->y && draw.y < WINDOW_Y && draw.x < WINDOW_X)
	{
		image_set_pixel(img_data, draw.x, draw.y,
			get_color(&from->color, &to->color, draw.dy, draw.y - from->y));
		if (draw.difference > 0)
		{
			draw.x += draw.step;
			draw.difference -= draw.d_dy;
		}
		draw.difference += draw.d_dx;
		draw.y++;
	}
}

void			draw_line(t_point *from, t_point *to, uint32_t *img_data)
{
	if (ABS(to->x - from->x) > ABS(to->y - from->y))
	{
		if (to->x > from->x)
			draw_line_right(from, to, img_data);
		else
			draw_line_right(to, from, img_data);
	}
	else
	{
		if (to->y > from->y)
			draw_line_down(from, to, img_data);
		else
			draw_line_down(to, from, img_data);
	}
}
