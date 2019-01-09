# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 09:52:35 by aspizhav          #+#    #+#              #
#    Updated: 2018/11/26 12:56:48 by aspizhav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror -c
SRC = ft_isalnum.c	ft_itoa.c		ft_memcpy.c	 ft_putchar_fd.c  ft_putstr.c\
	  ft_strcmp.c	ft_striter.c	ft_strmap.c	 ft_strnequ.c	  ft_strsub.c\
	  ft_isalpha.c  ft_memalloc.c	ft_memdel.c	 ft_putendl.c 	ft_putstr_fd.c\
	  ft_strcpy.c	ft_striteri.c	ft_strmapi.c ft_strnew.c    ft_strtrim.c\
	  ft_isascii.c  ft_memccpy.c	ft_memmove.c ft_putendl_fd.c ft_strcat.c\
 	  ft_strdel.c	ft_strjoin.c	ft_strncat.c ft_strnstr.c	ft_tolower.c\
ft_atoi.c	ft_isdigit.c	ft_memchr.c	ft_memset.c	ft_putnbr.c	ft_strchr.c\
ft_strdup.c	ft_strlcat.c	ft_strncmp.c	ft_strstr.c	ft_toupper.c\
ft_bzero.c	ft_isprint.c	ft_memcmp.c	ft_putchar.c	ft_putnbr_fd.c \
ft_strclr.c	ft_strequ.c	ft_strlen.c	ft_strncpy.c ft_lstnew.c ft_lstdelone.c\
ft_lstdel.c	ft_lstadd.c	ft_lstiter.c ft_lstmap.c ft_strsplit.c ft_strrchr.c\
ft_strrev.c ft_list_reverse.c ft_isprime.c ft_sqrt.c ft_print_memory.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAG) $(SRC) 
	@ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
