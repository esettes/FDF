/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:26:48 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/18 20:50:22 by iostancu         ###   ########.fr       */
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
/**
 * Sets the position of the first pixel to start drawing.
 * 
 * @param map The struct map.
 */
void	print_info(t_vec2 vertices);
void	set_initial_sizes(t_map *m, int x, int y);

#endif