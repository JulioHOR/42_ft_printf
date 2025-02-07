/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 00:00:34 by juhenriq          #+#    #+#             */
/*   Updated: 2025/01/24 20:21:31 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	to_string_int(t_fmt_spec *tfmt_spec, int integer)
{
	tfmt_spec->out_cont = (ft_itoa(integer));
}
