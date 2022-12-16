/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:51:50 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/16 18:56:53 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_rgb_parts(t_rgba *rgba, t_iter *iter, t_iter *save, size_t i);
static void	init_rgba(t_rgba *rgba);
static int	hex_char_to_int(char c);

int	str_to_color(char *color)
{
	unsigned long	int_color;
	char			*aux;
	t_rgba			rgba;
	t_iter			iter;
	t_iter			save;
	int				i;

	aux = color;
	init_rgba(&rgba);
	iter.i = 0;
	iter.j = 1;
	i = ft_strlen(color) - 1;
	int_color = 0;
	while (i >= 0)
	{
		if (aux[iter.i] == 'x' || aux[iter.i] == '\0')
			break ;
		iter.j = hex_char_to_int(aux[iter.i]);
		set_rgb_parts(&rgba, &iter, &save, i);
		save.i = iter.j;
		i--;
		iter.i++;
	}
	int_color = split_rgb(rgba.r, rgba.g, rgba.b, rgba.a);
	return (int_color);
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

static void	init_rgba(t_rgba *rgba)
{
	rgba->r = 0;
	rgba->g = 0;
	rgba->b = 0;
	rgba->a = 255;
}

static int	hex_char_to_int(char c)
{
	size_t	trigger;
	char	*hex;
	char	*hex2;
	t_iter	iter;

	iter.i = 0;
	trigger = FALSE;
	hex = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	if (!c)
		return (iter.i);
	while (hex[iter.i])
	{
		if (c == hex[iter.i])
		{
			trigger = TRUE;
			return (iter.i);
		}
		iter.i++;
	}
	iter.i = 0;
	if (trigger == FALSE)
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
/*
"0123456789abcdef"

1 2 4 8 16 32 64 128 256 512 1024 2048 4096 

8 4 2 1
0 0 0 0

15
1111 = 8+4+2+1

0010 2
0011 3
0100 4
1011 11

6 0110
12 1100


0000 0000  0000 0000  0000 0000  0000 0000 

f0f5 = f0f50000

f = 11111 = 15

*/

/*
pos = 7


color = 0
// color = 0000 0000  0000 0000  0000 0000  0000 0000 

f -> 1111

c = 15
// c = 0000 0000  0000 0000  0000 0000  0000 1111 

c = c << (pos * 4)
// c = 1111 0000  0000 0000  0000 0000  0000 0000 

color = color | c
//         0000 0000  0000 0000  0000 0000  0000 0000 
//         1111 0000  0000 0000  0000 0000  0000 0000 
// color = 1111 0000  0000 0000  0000 0000  0000 0000 

pos--

// Siguiente char
0 -> 0000

c = 0
// c = 0000 0000  0000 0000  0000 0000  0000 0000 

c = c << (pos * 4)
// c = 0000 0000  0000 0000  0000 0000  0000 0000 

color = color | c
//         1111 0000  0000 0000  0000 0000  0000 0000 
//         0000 0000  0000 0000  0000 0000  0000 0000 
// color = 1111 0000  0000 0000  0000 0000  0000 0000 

pos--

// Siguiente char
f -> 1111

c = 15
// c = 0000 0000  0000 0000  0000 0000  0000 1111 

c = c << (pos * 4)
// c = 0000 0000  1111 0000  0000 0000  0000 0000 

color = color | c
//         1111 0000  0000 0000  0000 0000  0000 0000 
//         0000 0000  1111 0000  0000 0000  0000 0000 
// color = 1111 0000  1111 0000  0000 0000  0000 0000 

pos--

// Siguiente char
5 -> 0101

c = 5
// c = 0000 0000  0000 0000  0000 0000  0000 0101

c = c << (pos * 4)
// c = 0000 0000  0000 0101  0000 0000  0000 0000 

color = color | c
//         1111 0000  1111 0000  0000 0000  0000 0000 
//         0000 0000  0000 0101  0000 0000  0000 0000 
// color = 1111 0000  1111 0101  0000 0000  0000 0000 

pos--
*/
