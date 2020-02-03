/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   world.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 13:12:51 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:38:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include "fdf.h"

int		world_load_object(char *filename, t_world *world);
int		world_remove_object(char *filename, t_world *world);
void	wold_select_next_object(t_world *world);

#endif
