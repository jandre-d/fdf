/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 08:31:04 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 12:36:59 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_X 2400
# define WINDOW_Y 1350
# define BPP 4
# include <stdint.h>
# include "libft/libft.h"
# define PI_OVER_180 0.0174532925199432957692
# define POINT_SPACEING 20
# define DEFAULT_SCALE 5
# define PROJECTION_ISO 2
# define PROJECTION_PARALLEL 1

typedef	struct	s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}				t_color;

typedef struct	s_point
{
	int32_t	x;
	int32_t	y;
	t_color	color;
}				t_point;

typedef struct	s_vector3
{
	double	x;
	double	y;
	double	z;
	t_color	color;
}				t_vector3;

/*
**	r_loc : relative location
*/
typedef struct	s_object_point
{
	t_vector3	r_loc;
	t_color		color;
}				t_object_point;

/*
**	a_loc : absolute location
*/
typedef struct	s_object_elem
{
	t_object_point			**vectors;
	uint32_t				size_y;
	uint32_t				size_x;
	t_vector3				a_loc;
	t_vector3				rotation;
	char					*filename;
	struct s_object_elem	*next;
}				t_object_elem;

/*
**	fname_selec_obj : filename selected object
*/
typedef struct	s_world
{
	t_object_elem	*object_list;
	t_object_elem	*selected_obj;
	int8_t			projection_type;
	int8_t			only_project_selected_object;
}				t_world;

typedef struct	s_user_control
{
	int8_t	mouse1_down;
	int8_t	ctrl_down;
	int32_t prev_x;
	int32_t prev_y;
}				t_user_control;

typedef struct	s_fdf
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	uint32_t			*img_data_ptr;
	t_world				world;
	t_user_control		user_control;
}				t_fdf;

typedef struct	s_input_list_point
{
	int32_t						height;
	struct s_input_list_point	*next;
}				t_input_list_point;

typedef struct	s_input_list_line
{
	t_input_list_point			*point_list;
	uint32_t					point_count;
	struct s_input_list_line	*next;
}				t_input_list_line;

typedef struct	s_input_lines
{
	t_input_list_line			*line_list;
	uint32_t					line_count;
}				t_input_list_lines;

/*
** result from reading one heightmap
*/
typedef struct	s_input
{
	t_input_list_lines	*list;
	char				*filename;
	uint16_t			heightmap_size_x;
	uint16_t			heightmap_size_y;
}				t_input;

/*
** "step" is to be added to x or y every loop.
** "d_dy" and "d_dx" are for calculating the "difference" beteen the \
** theoretical line and the line we have to draw.
*/
typedef struct	s_draw_line
{
	int32_t	dy;
	int32_t	dx;
	int32_t	step;
	int32_t	y;
	int32_t	x;
	int32_t	d_dy;
	int32_t	d_dx;
	int32_t	difference;
}				t_draw_line;

#endif
