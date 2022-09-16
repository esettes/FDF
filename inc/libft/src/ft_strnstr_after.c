/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:41:07 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/27 16:44:29 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr_after(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	hay = (char *)haystack;
	if (*needle == '\0')
		return (hay);
	i = 0;
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return (&hay[i + 1]);
			j++;
		}
		i++;
	}
	return (NULL);
}
