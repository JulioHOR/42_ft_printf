/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 06:33:22 by juhenriq          #+#    #+#             */
/*   Updated: 2025/01/18 02:48:15 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	to_string_char(t_fmt_spec *tfmt_spec, char c)
{
	char	*str;

	str = (char *) malloc(sizeof(c) + 1);
	if (!(str))
	{
		tfmt_spec->out_cont = NULL;
		return ;
	}
	str[0] = c;
	str[1] = '\0';
	tfmt_spec->out_cont = str;
}
