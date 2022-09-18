/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:25:48 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/08 16:44:03 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "structs.h"

void	draw_segment_to_right(t_vec2 start, t_vec2 end, t_fdf *fdf, float color);
void	draw_segment_to_left(t_vec2 start, t_vec2 end, t_fdf *fdf, float color);
void	draw_menu(t_fdf *fdf);
void	print_box_menu(t_fdf *fdf, int color, int max_x, int max_y);

void	zoom(t_fdf *fdf);

#endif