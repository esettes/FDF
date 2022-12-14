/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:41:20 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/19 00:41:42 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	*ft_memmove_gnl(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (NULL == dst && NULL == src)
		return (dst);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

size_t	ft_strlen_eol(const char *s, int lineLenght)
{
	size_t	i;

	i = 0;
	if (lineLenght == FALSE)
		while (s[i])
			i++;
	else
	{
		while (s[i] && s[i] != '\n')
			i++;
		if (s[i] == '\n')
			i++;
	}
	return (i);
}

int	ft_strchr_gnl(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	if (!s)
		return (FALSE);
	str = (unsigned char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (TRUE);
		i++;
	}
	if (str[i] == (char)c)
		return (TRUE);
	return (FALSE);
}

char	*ft_calloc_gnl(size_t count, size_t size)
{
	char	*res;
	size_t	i;
	size_t	all_size;

	all_size = count * size;
	res = malloc(all_size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < all_size)
		*(res + i++) = 0;
	return (res);
}
