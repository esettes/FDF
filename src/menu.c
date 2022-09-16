/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/09 22:47:21 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_fdf *fdf)
{
	t_vec2	aux;

	aux.x  = (WIDTH * IMG_AUMENT) / 1.5 - (WIDTH * 0.25);
	aux.y = (HEIGHT * IMG_AUMENT) / 1.5 - (HEIGHT * 0.25);
	mlx_put_string(fdf->mlx, "CONTROLS", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "Scroll for zoom", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[W][A][S][D] for directional movement", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[I] Isometric view", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[T] Top view", aux.x + 10, aux.y += 22);
}