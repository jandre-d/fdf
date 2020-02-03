# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/19 16:29:46 by jandre-d       #+#    #+#                 #
#    Updated: 2019/03/21 12:15:51 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FILES = draw get_next_line height_color image input_list input \
main object_movement object project_parallel user_input_keyboard \
user_input_mouse vector world

$(NAME):
	cd minilibx_macos && make
	cd libft && make
	gcc $(FILES:=.c) -lmlx -lft -framework OpenGl -framework AppKit \
		-L minilibx_macos/ -L libft/ -o $(NAME)

clean:
	cd minilibx_macos && make clean
	cd libft && make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)
