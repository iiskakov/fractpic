# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 18:03:06 by iiskakov          #+#    #+#              #
#    Updated: 2019/03/09 16:04:42 by iiskakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	 ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c  \
	 ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_memdel.c \
	 ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
	 ft_strchr.c ft_strclr.c ft_strcpy.c ft_strdup.c ft_strequ.c  \
	 ft_striteri.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strncat.c \
	 ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c \
	 ft_strstr.c ft_tolower.c ft_toupper.c ft_wordcount.c ft_itoa_base.c \
	 ft_memalloc.c ft_strcmp.c ft_iswspace.c ft_memcpy.c ft_memmove.c \
	 ft_wordlen.c ft_strjoin.c ft_strnstr.c ft_strmapi.c ft_itoa.c \
	 ft_striter.c ft_strdel.c ft_memchr.c ft_memccpy.c ft_memcmp.c \
	 ft_memset.c ft_strsub.c ft_strtrim.c ft_lstnew.c ft_strsplit.c \
	 ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	 ft_abs.c get_next_line.c\

OBJECTS=ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
	 ft_isdigit.o ft_islower.o ft_isprint.o ft_isspace.o ft_isupper.o  \
	 ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_memdel.o \
	 ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o \
	 ft_strchr.o ft_strclr.o ft_strcpy.o ft_strdup.o ft_strequ.o  \
	 ft_striteri.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strncat.o \
	 ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strrchr.o \
	 ft_strstr.o ft_tolower.o ft_toupper.o ft_wordcount.o ft_itoa_base.o \
	 ft_memalloc.o ft_strcmp.o ft_iswspace.o ft_memcpy.o ft_memmove.o  \
	 ft_wordlen.o ft_strjoin.o ft_strnstr.o ft_strmapi.o ft_itoa.o \
	 ft_striter.o ft_strdel.o ft_memchr.o ft_memccpy.o ft_memcmp.o \
	 ft_memset.o ft_strsub.o ft_strtrim.o ft_lstnew.o ft_strsplit.o \
	 ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o \
	 ft_abs.o get_next_line.o \

INCLUDES=./


all: $(NAME)

$(NAME): $(SRCS) libft.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean:	clean
	@/bin/rm -f $(NAME)

re:	fclean all