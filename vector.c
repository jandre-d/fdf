/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 17:30:31 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:48:26 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

void		vector3_free(t_vector3 *vector)
{
	ft_memdel((void **)&vector);
}

t_vector3	*vector3_new(double x, double y, double z)
{
	t_vector3 *to_return;

	to_return = NEW(t_vector3);
	if (to_return == NULL)
		return (NULL);
	to_return->x = x;
	to_return->y = y;
	to_return->z = z;
	return (to_return);
}

void		vector_rotate_x(double rot, t_vector3 *v)
{
	double y;
	double z;
	double v_cos;
	double v_sin;

	y = v->y;
	z = v->z;
	v_cos = cos(rot);
	v_sin = sin(rot);
	v->y = y * v_cos - z * v_sin;
	v->z = y * v_sin + z * v_cos;
}

void		vector_rotate_y(double rot, t_vector3 *v)
{
	double x;
	double z;
	double v_cos;
	double v_sin;

	x = v->x;
	z = v->z;
	v_cos = cos(rot);
	v_sin = sin(rot);
	v->x = x * v_cos + z * v_sin;
	v->z = -x * v_sin + z * v_cos;
}

void		vector_rotate_z(double rot, t_vector3 *v)
{
	double x;
	double y;
	double v_cos;
	double v_sin;

	x = v->x;
	y = v->y;
	v_cos = cos(rot);
	v_sin = sin(rot);
	v->x = v_cos * x - v_sin * y;
	v->y = v_sin * x + v_cos * y;
}
