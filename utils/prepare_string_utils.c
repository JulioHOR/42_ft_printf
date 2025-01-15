/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_string_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:35:42 by juhenriq          #+#    #+#             */
/*   Updated: 2025/01/14 19:00:29 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_nb_of_fmt_spec_nodes(t_fmt_spec *curr_fmt_spec)
{
	int	i;

	if (!(curr_fmt_spec))
		return (0);
	i = 1;
	while (curr_fmt_spec)
	{
		curr_fmt_spec = curr_fmt_spec->next_fmt_spec;
		i++;
	}
	return (i);
}

int	flags_in_this_node(t_fmt_spec *tfmt_spec)
{
	t_flags		*flags;

	flags = &(tfmt_spec->flags);
	if (flags->alignment || flags->fill_zero || flags->precision
		|| flags->prefixe || flags->force_plus_sign || flags->insert_spaces)
		return (1);
	return (0);
}

int	is_there_any_fmt_spec(t_input *tinput_str)
{
	if (get_nb_of_fmt_spec_nodes(tinput_str->tfmt_spec) > 0)
		return (1);
	else
		return (0);
}

int	calculate_final_string_len(t_input *tinput_str)
{
	t_fmt_spec	*curr_tfmt_spec;
	int			total_content_len;
	int			minus_spec_idxs;

	total_content_len = 0;
	minus_spec_idxs = 0;
	curr_tfmt_spec = tinput_str->tfmt_spec;
	while (curr_tfmt_spec)
	{
		total_content_len += curr_tfmt_spec->output_content_len;
		minus_spec_idxs += 1 + curr_tfmt_spec->end_idx - \
			curr_tfmt_spec->start_idx;
		curr_tfmt_spec = curr_tfmt_spec->next_fmt_spec;
	}
	return (ft_strlen(tinput_str->input_str) + \
		total_content_len - minus_spec_idxs);
}

void	get_raw_string(t_fmt_spec *tfmt_spec, va_list var_args)
{
	t_data_type	this_data_type;

	this_data_type = tfmt_spec->data_type;
	if (this_data_type == TYPE_CHAR)
		to_string_char(tfmt_spec, va_arg(var_args, unsigned int));
	if (this_data_type == TYPE_STRING)
		to_string_string(tfmt_spec, va_arg(var_args, char *));
	if (this_data_type == TYPE_POINTER)
		to_string_pointer(tfmt_spec, va_arg(var_args, void *), 1);
	if (this_data_type == TYPE_INT)
		to_string_int(tfmt_spec, va_arg(var_args, int));
	if (this_data_type == TYPE_EXPANDED_BASE_INT)
		to_string_int(tfmt_spec, va_arg(var_args, int));
	if (this_data_type == TYPE_UNSIGNED_INT)
		to_string_unsigned_int(tfmt_spec, va_arg(var_args, unsigned int));
	if (this_data_type == TYPE_LOWER_HEX)
		to_string_hex(tfmt_spec, va_arg(var_args, uintptr_t), 0, 0);
	if (this_data_type == TYPE_UPPER_HEX)
		to_string_hex(tfmt_spec, va_arg(var_args, uintptr_t), 1, 0);
	if (this_data_type == TYPE_PERCENT_SIGN)
		to_string_percent(tfmt_spec);
}
