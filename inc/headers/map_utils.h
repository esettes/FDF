/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_properties.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:26:48 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/25 00:47:38 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include "structs.h"

/**
 * Saves vertices of readed file.
 * 
 * @param[in] x Number of vertical vertices.
 * @param[in] y Number of horizontal vertices.
 * 
 * @return t_vec2 with the number of vertices.
 */
t_vec2	set_mtrx_size(int x, int y);
/**
 * Obtains the size in pixels of the mesh. Useful to set the mesh in center of
 * image.
 */
void	set_pixel_size(t_fdf *fdf);
void	init_map_props(t_fdf *fdf);
void	free_props(t_fdf *fdf);
/**
 * Sets the position of the first pixel to start drawing.
 * 
 * @param map The struct map.
 */
void	set_limits(t_map *map);
void	set_new_limits(t_fdf *fdf);
void	set_start_to_print_iso(t_fdf *fdf, t_vec2 *start, t_vec2 *end);
void    set_map_size(t_fdf *fdf, char *raw_map);
void	set_map_info(t_fdf *fdf, char *raw_map);

#endif