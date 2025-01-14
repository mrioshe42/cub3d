# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 18:44:21 by mrios-he          #+#    #+#              #
#    Updated: 2024/03/08 12:20:25 by mrios-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_strlen.c	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_striteri.c ft_strrchr.c \
	ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

B_SRCS = ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
	ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

B_OBJS = $(B_SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(B_OBJS)
	ar rcs $(NAME) $(OBJS) $(B_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
