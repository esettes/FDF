/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:27:13 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 13:17:35 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_memory(const char **arr, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < pos)
	{
		free ((void *)arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static size_t	str_count(char const *s, char c)
{
	size_t	count;
	size_t	bo;
	char	*a;

	count = 0;
	bo = 0;
	a = (char *)s;
	if (!a)
		return (0);
	while (*a)
	{
		if (*a != c && bo == 0)
		{
			count++;
			bo = 1;
		}
		if (*a == c)
			bo = 0;
		a++;
	}
	return (count);
}

static void	*set_pos(char const *s, size_t j_init, size_t i_fin)
{
	size_t	j;
	char	*str;
	char	*b;

	j = 0;
	str = malloc(sizeof(char) * (i_fin - j_init + 1));
	b = (char *)s;
	if (!str)
		return (NULL);
	while (j_init < i_fin)
		str[j++] = b[j_init++];
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	pos;

	i = -1;
	pos = 0;
	arr = malloc(sizeof(char *) * ((str_count(s, c)) + 1));
	if (!arr)
		return (NULL);
	while (++i < ft_strlen(s) && pos < str_count(s, c))
	{
		if (*(s + i) != c)
		{
			j = i;
			while (i <= ft_strlen(s) && *(s + i) != c && *s)
				i++;
			arr[pos++] = set_pos(s, j, i);
			if (arr[pos - 1] == NULL)
				return (free_memory((const char **)arr, pos));
		}
	}
	arr[pos] = 0;
	return (arr);
}
