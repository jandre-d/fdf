/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/02 10:46:04 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:38:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "fdf.h"

t_object_elem		*object_elem_from_input(t_input *input);
void				object_free(t_object_elem *obj);

#endif
