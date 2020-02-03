/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_list.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 17:01:34 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:50:30 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_LIST_H
# define INPUT_LIST_H
# include "fdf.h"

void free_split(char **split);
void input_list_add_point_to_line(t_input_list_point *add,
t_input_list_line *line);
void input_list_add_line_to_list(t_input_list_line *add,
t_input_list_lines *to);

#endif
