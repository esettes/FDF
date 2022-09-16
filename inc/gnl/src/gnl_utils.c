/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:12:59 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 13:14:41 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

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

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	s2_len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s2_len = ft_strlen_eol(s2, FALSE);
	res = malloc(sizeof(char) * (ft_strlen_eol(s1, FALSE) + s2_len + 1));
	if (!res)
		return (NULL);
	while (s1[i])
		res[i++] = (char)s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

int	ft_strchr_gnl(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (FALSE);
	str = (char *)s;
	while (str[i] > '\0')
	{
		if (str[i] == (char)c)
			return (TRUE);
		i++;
	}
	if (str[i] == (char)c)
		return (TRUE);
	return (FALSE);
}

char	*ft_strdup_gnl(const char *s1)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = malloc(ft_strlen_eol(s1, FALSE) + 1);
	if (!cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
