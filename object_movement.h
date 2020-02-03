/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_movement.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/02 13:29:04 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:38:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_MOVEMENT_H
# define OBJECT_MOVEMENT_H
# include "fdf.h"

void	obj_move(double x, double y, double z, t_object_elem *obj);
void	obj_rot(double x_deg, double y_deg, double z_deg, t_object_elem *obj);
void	obj_scale(double x, double y, double z, t_object_elem *obj);
void	obj_to_iso(t_object_elem *obj);
void	obj_rot_iso(double x_deg, double y_deg, double z_deg,
	t_object_elem *obj);

#endif
