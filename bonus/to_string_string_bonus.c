/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:01:23 by juhenriq          #+#    #+#             */
/*   Updated: 2025/01/16 20:37:32 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	to_string_string(t_fmt_spec *tfmt_spec, char *str)
{
	if (!(str))
		tfmt_spec->out_cont = ft_strdup("(null)");
	else
		tfmt_spec->out_cont = ft_strdup(str);
}
