/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 10:48:53 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/20 12:15:47 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_fd_list
{
	ssize_t				fd;
	ssize_t				buffer_usage;
	char				*buffer;
	struct s_fd_list	*next;
}						t_fd_list;

int						get_next_line(const int fd, char **line);

#endif
