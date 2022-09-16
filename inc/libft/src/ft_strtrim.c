/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:06:23 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 13:16:07 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	char	*p;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == 0)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1) - 1;
	if (!s1)
		return ((char *)s1);
	while (check_char(set, *(char *)(s1 + i)))
		i++;
	while (check_char(set, *(char *)(s1 + j)) && j >= i)
		j--;
	cpy = (char *)malloc(sizeof(char) * (j - i) + 2);
	p = cpy;
	if (!p)
		return (NULL);
	while (i <= j)
		*cpy++ = *(char *)(s1 + i++);
	*cpy = '\0';
	return (p);
}
