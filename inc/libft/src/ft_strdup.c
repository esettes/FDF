/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:20:53 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 13:17:04 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s1, ft_strlen(s1) + 1);
	return (cpy);
}
