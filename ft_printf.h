/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:34:09 by juhenriq          #+#    #+#             */
/*   Updated: 2025/01/15 03:11:16 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft/libft.h"

typedef enum e_data_type
{
	TYPE_CHAR,
	TYPE_STRING,
	TYPE_POINTER,
	TYPE_INT,
	TYPE_EXPANDED_BASE_INT,
	TYPE_UNSIGNED_INT,
	TYPE_LOWER_HEX,
	TYPE_UPPER_HEX,
	TYPE_PERCENT_SIGN
}	t_data_type;

typedef struct s_flags
{
	int	alignment;
	int	fill_zero;
	int	precision;
	int	prefixe;
	int	force_plus_sign;
	int	insert_spaces;
}	t_flags;

typedef struct s_fmt_spec
{
	t_data_type			data_type;
	t_flags				flags;
	int					start_idx;
	int					end_idx;
	char				*out_cont;
	int					output_content_len;
	struct s_fmt_spec	*next_fmt_spec;
}	t_fmt_spec;

typedef struct s_input
{
	const char		*input_str;
	char			*output_str;
	int				output_str_len;
	t_fmt_spec		*tfmt_spec;
}	t_input;

int			calculate_final_string_len(t_input *tinput_str);
t_fmt_spec	*create_fmt_specifier(int fmt_start_idx);
t_input		*create_tinput_str(const char *string);
int			determine_data_type(t_fmt_spec	*tfmt_spec, const char *string, \
	int i);
void		flags_check(char character, t_fmt_spec *tfmt_spec);
int			flags_in_this_node(t_fmt_spec *tfmt_spec);
int			find_char(const char *str, char target_char, int start);
int			ft_printf(const char *string, ...);
int			ft_printf_free_everything(t_input	**tinput_str);
void		get_raw_string(t_fmt_spec *tfmt_spec, va_list var_args);
char		*get_output_string(t_input *tinput_str, va_list va_args);
int			identify_specifiers(t_input *tinput_str);
int			is_there_any_fmt_spec(t_input *tinput_str);
char		*modified_ft_strdup(char *str, unsigned long max_idx);
int			simplified_data_type_check(char character);
void		to_string_char(t_fmt_spec *tfmt_spec, char c);
void		to_string_hex(t_fmt_spec *tfmt_spec, uint64_t nb, int case_flag, \
	int hex_or_ptr);
void		to_string_int(t_fmt_spec *tfmt_spec, int integer);
void		to_string_percent(t_fmt_spec *tfmt_spec);
void		to_string_pointer(t_fmt_spec *tfmt_spec, void *ptr, int hex_or_ptr);
void		to_string_string(t_fmt_spec *tfmt_spec, char *str);
void		to_string_unsigned_int(t_fmt_spec *tfmt_spec, unsigned int n);
char		*unsigned_hex_int_to_hex(unsigned int number, int case_flag);
char		*unsigned_ptr_int_to_hex(uint64_t number, int case_flag);
char		*copy_input_str_and_exit(t_input *tinput);

#endif