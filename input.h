/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 13:57:39 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/19 16:38:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include "fdf.h"

void	input_free(t_input *input);
t_input	*input_get(int fd);

#endif
