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
void	init_mlx(t_fdf *fdf);
/* Calls all functions that need mlx_loop to run */
void	loop_fdf(t_fdf *fdf);
void	create_image(t_fdf *fdf);
void	draw_image(t_fdf *fdf);
/**
 * Calls create_image() and draw_image().
 */
void	modify_mesh(t_fdf *fdf);

#endif