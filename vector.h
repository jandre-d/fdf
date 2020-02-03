/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 17:30:28 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:38:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "fdf.h"

void		vector_rotate_x(double rot, t_vector3 *v);
void		vector_rotate_y(double rot, t_vector3 *v);
void		vector_rotate_z(double rot, t_vector3 *v);
void		vector3_free(t_vector3 *vector);
t_vector3	*vector3_new(double x, double y, double z);

#endif
