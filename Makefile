# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtroll <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 23:15:17 by rtroll            #+#    #+#              #
#    Updated: 2019/01/17 16:04:20 by rtroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_atoi.c ft_isdigit.c\
	  ft_print_sub.c ft_itoa.c ft_memalloc.c\
	  ft_print_data.c ft_memset.c ft_putchar.c\
	  ft_print_char.c ft_strcat.c ft_strchr.c\
	  ft_print_string.c ft_strcpy.c ft_strdel.c\
	  ft_print_pointer.c ft_strdup.c ft_strjoin.c\
	  ft_print_decimal.c ft_strlen.c ft_strncpy.c\
	  ft_print_octal.c ft_strnew.c ft_strrchr.c\
	  ft_print_unsigned.c ft_strrev.c ft_strstr.c\
	  ft_print_hex.c ft_memcpy.c ft_memdel.c\
	  ft_print_hex_capital.c ft_putstr.c ft_strsub.c\
	  ft_print_float.c\
	  ft_print_percent.c\
	  ft_print_no_spec.c\
	  ft_check_point.c\
	  ft_prec.c\
	  ft_prec_h.c\
	  ft_prec_h_capital.c\
	  ft_prec_o.c\
	  ft_prec_p.c\
	  ft_prec_u.c\
	  ft_print_unicode_char.c\
	  ft_change_format.c\
	  ft_change_format_h.c\
	  ft_change_format_h_capital.c\
	  ft_change_format_pointer.c\
	  ft_change_format_o.c\
	  ft_print_regular_string.c\
	  ft_find_l.c\
	  ft_change_format_u.c\
	  ft_change_format_float.c\
	  ft_round.c

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH), $(SRC))

INC = -I ./include/

CC = gcc

FLAGS = -Wextra -Wall -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ):
	    @$(CC) $(FLAGS) -c $(SRC_POS) $(INC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
