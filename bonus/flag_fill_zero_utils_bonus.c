/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_fill_zero_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:24:53 by juhenriq          #+#    #+#             */
/*   Updated: 2025/02/01 03:39:29 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_ptr_modifier(t_fmt_spec *tfmt_spec)
{
	if (tfmt_spec->data_type == TYPE_POINTER)
		return (2);
	else
		return (0);
}
