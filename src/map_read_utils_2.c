/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:54:14 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/19 01:23:00 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "colors.h"
#include "libft.h"

int	check_valid_map(char **map, t_vec2 size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (!(ft_strncmp(&map[i][j], " ", 1) == 0
				|| ft_strncmp(&map[i][j], "\n", 1) == 0
				|| ft_isalnum(map[i][j])
				|| ft_strncmp(&map[i][j], "-", 1) == 0
				|| ft_strncmp(&map[i][j], "+", 1) == 0
				|| ft_strncmp(&map[i][j], ",", 1) == 0))
			{
				ft_putendl_fd(RED_, "Error: Invalid map.", 1);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

size_t	count_spaces(const char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == ' ' && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			if (s[i + 1] != ' ')
				len++;
		}
		i++;
	}
	return (len);
}
