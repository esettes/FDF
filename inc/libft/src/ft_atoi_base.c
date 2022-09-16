/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:33:39 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/04 17:34:09 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_prefix(const char *str, int base)
{
	int	i;

	i = 0;
	if (base == 2 || base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (1);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (1);
	}
	return (0);
}

static int	ft_isdigit_base(char c, int size)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEFGHIJK";
	i = 0;
	while (i < size)
	{
		if (base[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;

	result = 0;
	i = 0;
	if (base == 10)
		return (ft_atoi(str));
	while (ft_isspace(str[i]))
		i++;
	if (has_prefix(&str[i], base))
		i += 2;
	else if (base == 8)
		i++;
	while (ft_isdigit_base(str[i], base) >= 0)
		result = (result * base) + ft_isdigit_base(str[i++], base);
	return ((int)(result));
}