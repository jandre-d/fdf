# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/09 10:02:55 by jandre-d       #+#    #+#                 #
#    Updated: 2019/01/16 17:07:36 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_isupper ft_islower \
	ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove \
	ft_memchr ft_memcmp ft_strlen ft_strdup ft_strcpy \
	ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr \
	ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp \
	ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isascii \
	ft_isprint ft_toupper ft_tolower \
	ft_memalloc ft_memdel ft_strnew ft_strclr ft_strdel \
	ft_striter ft_striteri ft_strmap ft_strmapi \
	ft_strequ ft_strnequ ft_strsub ft_strjoin \
	ft_strtrim ft_strsplit ft_itoa ft_putchar ft_putstr \
	ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	ft_lstnew ft_lstdelone ft_lstdel \
	ft_lstadd ft_lstiter ft_lstmap \
	ft_strrev ft_islower ft_isupper
 
$(NAME):
	gcc -c -Wall -Wextra -Werror $(FILES:=.c)
	ar rc $(NAME) $(FILES:=.o)
	ranlib $(NAME)

clean:
	rm -f $(FILES:=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

so:
	gcc -shared -o libft.so -I. -Wall -Wextra -Werror -fPIC $(CFILES)
