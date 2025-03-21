/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:05:52 by juhenriq          #+#    #+#             */
/*   Updated: 2025/01/16 20:37:32 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	to_string_hex(t_fmt_spec *tfmt_spec, uint64_t nb, int case_flag, \
	int hex_or_ptr)
{
	if (hex_or_ptr)
		tfmt_spec->out_cont = unsigned_ptr_int_to_hex(nb, 0);
	else
	{
		if (case_flag)
			tfmt_spec->out_cont = unsigned_hex_int_to_hex(nb, 1);
		else
			tfmt_spec->out_cont = unsigned_hex_int_to_hex(nb, 0);
	}
}
