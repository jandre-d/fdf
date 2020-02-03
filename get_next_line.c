/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 10:48:57 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/21 11:53:50 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd_list	*get_fd_elem(int fd, t_fd_list **list)
{
	t_fd_list *search_elem;
	t_fd_list *new;

	search_elem = *list;
	if (search_elem != NULL && search_elem->fd == fd)
		return (*list);
	while (search_elem != NULL && search_elem->next != NULL)
	{
		if (search_elem->next->fd == fd)
			return (search_elem->next);
		search_elem = search_elem->next;
	}
	if (
	(new = (t_fd_list *)ft_memalloc(sizeof(t_fd_list))) == NULL ||
	(new->buffer = ft_strnew(BUFF_SIZE)) == NULL)
		return (NULL);
	new->fd = fd;
	return (search_elem == NULL
	?
	(*list = new) :
	(search_elem->next = new));
}

static void			free_fd_elem(t_fd_list **list, t_fd_list *elem)
{
	t_fd_list			*change;

	change = *list;
	while (change->next != NULL && change->next->fd != elem->fd)
		change = change->next;
	if (change->next == elem)
		change->next = change->next->next;
	else
		*list = elem->next;
	if (elem != NULL)
	{
		if (elem->buffer != NULL)
			ft_memdel((void **)&(elem->buffer));
		ft_memdel((void **)&elem);
	}
}

static char			*add_to_line(char **line, ssize_t *line_len, char *add,
		ssize_t add_len)
{
	char *new_line;

	new_line = ft_strnew(*line_len + add_len);
	if (new_line == NULL)
		return (NULL);
	ft_memcpy(new_line, *line, *line_len);
	ft_memcpy(new_line + *line_len, add, add_len);
	*line_len += add_len;
	if (line != NULL && *line != NULL)
		ft_strdel(line);
	*line = new_line;
	return (new_line);
}

static int			load_from_buffer(char **line, t_fd_list *elem,
		ssize_t *line_len)
{
	ssize_t nl_index;

	nl_index = 0;
	if (elem->buffer_usage == -1)
		return (-1);
	while (nl_index < elem->buffer_usage && elem->buffer[nl_index] != 0x0a)
		nl_index++;
	if (nl_index == elem->buffer_usage)
	{
		if (
		add_to_line(line, line_len, elem->buffer, elem->buffer_usage) == NULL)
			return (-1);
		line_len += elem->buffer_usage;
		return (0);
	}
	else
	{
		if (add_to_line(line, line_len, elem->buffer, nl_index) == NULL)
			return (-1);
		ft_memmove(elem->buffer, elem->buffer + nl_index + 1,
				elem->buffer_usage - (nl_index + (ssize_t)1));
		elem->buffer_usage -= nl_index + (ssize_t)1;
		return (1);
	}
}

int					get_next_line(int fd, char **line)
{
	static	t_fd_list	*list;
	t_fd_list			*elem;
	ssize_t				line_len;
	int					load_res;

	line_len = 0;
	if ((line == NULL || fd < 0 || BUFF_SIZE < 1) ||
	((*line = ft_strnew(0)) == NULL) ||
	((elem = get_fd_elem(fd, &list)) == NULL))
		return (-1);
	load_res = load_from_buffer(line, elem, &line_len);
	if (load_res != 0)
		return (load_res);
	while (
		(elem->buffer_usage = read(fd, elem->buffer, BUFF_SIZE)) != 0)
	{
		load_res = load_from_buffer(line, elem, &line_len);
		if (load_res == -1)
			free_fd_elem(&list, elem);
		if (load_res != 0)
			return (load_res);
	}
	free_fd_elem(&list, elem);
	return (line_len != 0);
}
