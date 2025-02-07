# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 23:02:41 by juhenriq          #+#    #+#              #
#    Updated: 2025/02/01 04:27:15 by juhenriq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

MANDATORY_SRCS = mandatory/ft_printf.c mandatory/prepare_string.c \
	mandatory/prepare_string_utils.c mandatory/printf_logic_utils.c \
	mandatory/to_string_char.c mandatory/to_string_hex.c \
	mandatory/to_string_int.c mandatory/to_string_percent.c \
	mandatory/to_string_pointer.c mandatory/to_string_string.c \
	mandatory/to_string_unsigned_int.c mandatory/to_string_unsigned_int_to_hex.c \
	mandatory/utils.c mandatory/flag_alignment.c \
	mandatory/format_especifier_content.c mandatory/flag_width.c \
	mandatory/flag_fill_zero.c mandatory/flag_precision.c \
	mandatory/flag_prefixe.c mandatory/flag_force_plus_sign.c \
	mandatory/flag_insert_spaces.c mandatory/flag_fill_zero_utils.c \
	mandatory/flag_precision_utils.c mandatory/flag_utils.c

BONUS_SRCS = bonus/ft_printf_bonus.c bonus/prepare_string_bonus.c \
	bonus/prepare_string_utils_bonus.c bonus/printf_logic_utils_bonus.c \
	bonus/to_string_char_bonus.c bonus/to_string_hex_bonus.c \
	bonus/to_string_int_bonus.c bonus/to_string_percent_bonus.c \
	bonus/to_string_pointer_bonus.c bonus/to_string_string_bonus.c \
	bonus/to_string_unsigned_int_bonus.c bonus/to_string_unsigned_int_to_hex_bonus.c \
	bonus/utils_bonus.c bonus/flag_alignment_bonus.c \
	bonus/format_especifier_content_bonus.c bonus/flag_width_bonus.c \
	bonus/flag_fill_zero_bonus.c bonus/flag_precision_bonus.c \
	bonus/flag_prefixe_bonus.c bonus/flag_force_plus_sign_bonus.c \
	bonus/flag_insert_spaces_bonus.c bonus/flag_fill_zero_utils_bonus.c \
	bonus/flag_precision_utils_bonus.c bonus/flag_utils_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(MANDATORY_OBJS)

bonus: clean_bonus $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJS)

clean_bonus:
	rm -f $(MANDATORY_OBJS)

mandatory/%.o: mandatory/%.c ft_printf.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c ft_printf_bonus.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re
