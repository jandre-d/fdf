/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_input_mouse.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 15:41:36 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:38:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INPUT_MOUSE_H
# define USER_INPUT_MOUSE_H
# include "fdf.h"

int mouse_press(int trash, int x, int y, void *fdf_var);
int mouse_release(int trash, int x, int y, void *fdf_var);
int mouse_move(int x, int y, void *fdf_var);

#endif
