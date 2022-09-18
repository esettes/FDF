/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:45:23 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/09 23:05:06 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_r(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

static int	get_g(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

static int	get_b(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

static int	get_a(int trgb)
{
	return (trgb & 0xFF);
}

int	separate_sections(unsigned int r, unsigned int g, unsigned int b,  unsigned int a)
{
	int	colors[4];

	colors[0] = get_r(r);
	colors[1] = get_g(g);
	colors[2] = get_b(b);
	colors[3] = get_a(255);
	
	return (r << 24 | g << 16 | b << 8 | a);
}