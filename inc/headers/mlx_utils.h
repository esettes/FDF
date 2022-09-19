/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:23:21 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 13:28:25 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "structs.h"

/* Initializes the main parameters of the application */
void	init_mlx(t_fdf *fdf, char *raw_map);
/* Calls all functions that need mlx_loop to run */
void	loop_fdf(t_fdf *fdf);
/*
 * Indicate if is the initialization image(0) creation or not(!0)
 */
int 	create_image(t_fdf *fdf, int start);
int 	draw_image(t_fdf *fdf);
/**
 * Calls create_image() and draw_image().
 */
int 	modify_mesh(t_fdf *fdf);

#endif