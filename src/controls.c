/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:51:18 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/16 20:58:19 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_img(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;
	keys_t	key;

	fdf = param;
	key = keydata.key;
	if (key == MLX_KEY_A && keydata.action == MLX_RELEASE
		&& keydata.modifier == MLX_CONTROL)
		puts("Gotta grab it all!");
	if (key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
	if ((key >= 262 && key <= 265))
		set_control_movement(keydata, fdf);
	else if (key == MLX_KEY_T || key == MLX_KEY_I)
		set_control_view(keydata, fdf);
	else if (key == MLX_KEY_N || key == MLX_KEY_M || key == 267
		|| key == 334 || key == 266)
		set_control_height(keydata, fdf);
	else if (key == MLX_KEY_Z || key == MLX_KEY_X)
		set_control_rotation(keydata, fdf);
	else if (key >= MLX_KEY_0 && key <= MLX_KEY_4)
		set_control_palette(keydata, fdf);
	else if (key >= MLX_KEY_B && key <= MLX_KEY_V)
		set_control_point_resolution(keydata, fdf);
}
