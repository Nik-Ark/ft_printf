# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lessie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/29 19:30:30 by lessie            #+#    #+#              #
#    Updated: 2020/12/06 16:17:52 by lessie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_proceed.c ft_printf_utils.c ft_itoa.c ft_itoa_base.c \
		ft_print_utils_2.c put_specifiers.c \

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

GCC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o: ft_printf.h
	$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) ft_printf.h
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
