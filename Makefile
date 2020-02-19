# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 22:43:32 by hhoummad          #+#    #+#              #
#    Updated: 2020/01/26 16:36:37 by hhoummad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	char_printer.c		\
		d_press.c			\
		digits_printer.c	\
		ft_atoi.c			\
		ft_d_assist.c		\
		ft_itoa.c			\
		ft_p.c				\
		ft_printf.c			\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_strchr.c			\
		hexa_code.c			\
		percent_pr.c		\
		printf_utils.c		\
		s_printer.c			\
		s_printer2.c		\
		u_assist.c			\
		u_printer.c			\
		hexa_printer.c		\
		ft_calloc.c			\
		ft_free_st.c

OBJ =	$(SRC:.c=.o)

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re : fclean all
