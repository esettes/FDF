/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:50:32 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 13:16:55 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (NULL);
		return (ft_strdup(s2));
	}
	res = (char *)malloc(ft_strlen((char *)s1) + (ft_strlen((char *)s2)) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
		res[i++] = (char)s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
