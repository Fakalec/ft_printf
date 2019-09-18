# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2018/12/19 16:31:33 by dstracke          #+#    #+#             #
#   Updated: 2019/01/23 17:17:03 by dstracke         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME	= libftprintf.a

SRCDIR	= source

LIBDIR	= lib_func

SRC		= $(addprefix $(SRCDIR)/, beautiful_way_for_life_cmon.c big_numbers_1_cmon.c \
            big_numbers_3_cmon.c build_it_cmon.c e_f_Changer_cmon.c ft_printf.c get_chirik_cmon.c \
            get_symbol_cmon.c output_chicken_swimming_pool_cmon.c output_date_cmon.c \
            output_swimming_pool_cmon.c output_symbol_cmon.c rasparsing_cmon.c big_numbers_2_cmon.c \
            output_easy_number_cmon.c get_dubler_cmon.c)

LIB		= $(addprefix $(LIBDIR)/, ft_atoi.c ft_bzero.c ft_isspace.c ft_memcpy.c ft_strcmp.c ft_strlen.c)

OBJ		= ${SRC:.c=.o} ${LIB:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I./includes -c -o $@ $<

$(LIBDIR)/%.o: $(LIBDIR)/%.c
	@$(CC) $(CFLAGS) -I./includes -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
