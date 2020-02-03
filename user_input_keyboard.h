/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_input_keyboard.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 15:41:39 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:38:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INPUT_KEYBOARD_H
# define USER_INPUT_KEYBOARD_H
# include "fdf.h"

int	key_press(int key, void *fdf_var);
int key_release(int key, void *fdf_var);

#endif
