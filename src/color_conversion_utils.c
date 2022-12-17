/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conversion_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:02:27 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/16 23:07:58 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "libft.h"
#include "colors.h"

static void	init_rgba(t_rgba *rgba)
{
	rgba->r = 0;
	rgba->g = 0;
	rgba->b = 0;
	rgba->a = 255;
}

int	get_upper_hex(char *hex, t_iter *iter, char c)
{
	while (hex[iter->i])
	{
		if (c == hex[iter->i])
			return (iter->i);
		iter->i++;
	}
	return (iter->i);
}

static int	hex_char_to_int(char c)
{
	size_t	trigger;
	char	*hex;
	char	*hex2;
	t_iter	iter;

	iter.i = 0;
	trigger = true;
	hex = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	if (!c)
		return (iter.i);
	while (hex[iter.i])
	{
		if (c == hex[iter.i])
		{
			trigger = true;
			return (iter.i);
		}
		iter.i++;
	}
	iter.i = 0;
	if (trigger == false)
		iter.i = get_upper_hex(hex2, &iter, c);
	return (iter.i);
}

static void	set_rgb_parts(t_rgba *rgba, t_iter *iter, t_iter *save, size_t i)
{
	if (i % 2 == 0)
	{
		save->j = iter->j;
		iter->j = save->i * iter->j;
		if (i == 4)
			rgba->r = iter->j;
		if (i == 2)
			rgba->g = iter->j;
		if (i == 0)
			rgba->b = iter->j;
	}
}

int	str_to_color(char *aux, int len, unsigned long int_color)
{
	t_rgba	rgba;
	t_iter	iter;
	t_iter	save;

	init_rgba(&rgba);
	iter.i = 0;
	iter.j = 1;
	while (len >= 0)
	{
		if (aux[iter.i] == 'x' || aux[iter.i] == '\0')
			break ;
		iter.j = hex_char_to_int(aux[iter.i]);
		set_rgb_parts(&rgba, &iter, &save, len);
		save.i = iter.j;
		len--;
		iter.i++;
	}
	int_color = sp_rgb(rgba.r, rgba.g, rgba.b, rgba.a);
	return (int_color);
}

int	hex_to_color(char *color)
{
	t_rgba	rgba;
	t_iter	iter;
	t_iter	save;
	unsigned long	int_color;
	char			*aux;
	int				len;

	aux = color;

	init_rgba(&rgba);
	iter.i = 0;
	iter.j = 1;
	int_color = 0;
	len = ft_strlen(color) - 1;
	while (len >= 0)
	{
		if (aux[iter.i] == 'x' || aux[iter.i] == '\0')
			break ;
		iter.j = hex_char_to_int(aux[iter.i]);
		set_rgb_parts(&rgba, &iter, &save, len);
		save.i = iter.j;
		len--;
		iter.i++;
	}
	int_color = sp_rgb(rgba.r, rgba.g, rgba.b, rgba.a);
	return (int_color);
}