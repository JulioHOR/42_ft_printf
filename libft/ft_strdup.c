/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhenriq <dev@juliohenrique.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:13:18 by juhenriq          #+#    #+#             */
/*   Updated: 2025/01/11 01:12:22 by juhenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		string_len;
	char	*copied_string;

	if (!(s))
		return (NULL);
	string_len = ft_strlen(s);
	copied_string = (char *) malloc(string_len + 1);
	if (!(copied_string))
		return (NULL);
	i = 0;
	while (i < (string_len + 1))
	{
		copied_string[i] = s[i];
		i++;
	}
	return (copied_string);
}
