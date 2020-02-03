/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 13:57:33 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:54:19 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "get_next_line.h"
#include "input_list.h"

static t_input_list_line	*input_list_get_line(char **points)
{
	t_input_list_line	*to_return;
	t_input_list_point	*point_elem;

	to_return = NEW(t_input_list_line);
	if (to_return == NULL)
		return (NULL);
	while (*points != '\0')
	{
		point_elem = NEW(t_input_list_point);
		if (point_elem == NULL)
		{
			return (NULL);
		}
		point_elem->height = ft_atoi((const char *)*points) * DEFAULT_SCALE;
		ft_memdel((void **)&(*points));
		input_list_add_point_to_line(point_elem, to_return);
		to_return->point_count++;
		points++;
	}
	return (to_return);
}

static t_input_list_lines	*input_list_get_lines(int fd)
{
	t_input_list_lines	*to_return;
	t_input_list_line	*lst_line;
	char				*line;
	char				**point;
	int32_t				res;

	to_return = NEW(t_input_list_lines);
	res = get_next_line(fd, &line);
	while (res > 0)
	{
		point = ft_strsplit((const char *)line, ' ');
		if (line != NULL)
			ft_memdel((void **)&line);
		lst_line = input_list_get_line(point);
		free_split(point);
		if (lst_line == NULL)
			return (NULL);
		input_list_add_line_to_list(lst_line, to_return);
		to_return->line_count++;
		res = get_next_line(fd, &line);
	}
	if (res <= 0)
		ft_memdel((void **)&line);
	return (res == -1 ? NULL : to_return);
}

static int					input_verify(t_input *input)
{
	uint16_t			target_points_per_line;
	t_input_list_line	*use_me;

	if (input->list == NULL || input->list->line_list == NULL)
	{
		return (-1);
	}
	use_me = input->list->line_list;
	target_points_per_line = use_me->point_count;
	while (use_me != NULL)
	{
		if (use_me->point_count != target_points_per_line)
		{
			return (-1);
		}
		use_me = use_me->next;
	}
	return (1);
}

void						input_free(t_input *input)
{
	t_input_list_point	*prev_point;
	t_input_list_line	*prev_line;

	while (input->list->line_list != NULL)
	{
		while (input->list->line_list->point_list != NULL)
		{
			prev_point = input->list->line_list->point_list;
			input->list->line_list->point_list =
				input->list->line_list->point_list->next;
			ft_memdel((void **)&prev_point);
		}
		prev_line = input->list->line_list;
		input->list->line_list = input->list->line_list->next;
		ft_memdel((void **)&prev_line);
	}
	ft_memdel((void **)&input->list);
	ft_memdel((void **)&input);
}

t_input						*input_get(int fd)
{
	t_input *to_return;

	to_return = NEW(t_input);
	to_return->list = input_list_get_lines(fd);
	if (to_return->list == NULL)
	{
		return (NULL);
	}
	if (input_verify(to_return) == -1)
	{
		return (NULL);
	}
	to_return->heightmap_size_y = to_return->list->line_count;
	to_return->heightmap_size_x = to_return->list->line_list->point_count;
	return (to_return);
}
