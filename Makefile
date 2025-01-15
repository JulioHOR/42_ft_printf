# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 23:02:41 by juhenriq          #+#    #+#              #
#    Updated: 2025/01/15 03:10:57 by juhenriq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ft_printf.c prepare_string.c utils/prepare_string_utils.c \
	   utils/printf_logic_utils.c \
	   utils/to_string_char.c utils/to_string_hex.c \
	   utils/to_string_int.c utils/to_string_percent.c \
	   utils/to_string_pointer.c utils/to_string_string.c \
	   utils/to_string_unsigned_int_to_hex.c \
	   utils/to_string_unsigned_int.c utils/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
