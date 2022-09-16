/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:51:50 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/12 16:57:01 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
void	init_rgba(t_rgba *rgba)
{
	rgba->r = 0;
	rgba->g = 0;
	rgba->b = 0;
	rgba->a = 255;
}

int		char_to_int(char c)
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
	{
		while (hex2[iter.i])
		{
			if (c == hex2[iter.i])
				return (iter.i);
			iter.i++;
		}
	}
	return (iter.i);
}

int		str_to_color(char *color)
{
	unsigned long		int_color;
	char	*aux;
	t_rgba	rgba;
	t_iter	iter;
	t_iter	uiter;
	t_iter	save;
	size_t	i;

	aux = color;
	init_rgba(&rgba);
	iter.i = 0;
	iter.j = 1;
	uiter.j = 1;
	i = ft_strlen(color) - 1;
	int_color = 0;
	while (i >= 0)
	{
		if ( aux[iter.i] == 'x' || aux[iter.i] == '\0')
			break ;
		uiter.j = char_to_int(aux[iter.i]);
		if (i % 2 == 0)
		{
			save.j = uiter.j; // solo para prueba, eliminar luego
			uiter.j = save.i * uiter.j;
			if (i == 4) // hay r,g y b y hay que guardar el red
				rgba.r = uiter.j;
			if (i == 2) // hay g y b y hay que guardar el green
				rgba.g = uiter.j;
			if (i == 0) // hay b y hay que guardar el blue
				rgba.b = uiter.j;
		}
		save.i = uiter.j;
		i--;
		iter.i++;
	}
	int_color = separate_sections(rgba.r, rgba.g, rgba.b, rgba.a);

	return (int_color);
}


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