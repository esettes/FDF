/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:50:04 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/19 00:05:57 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "structs.h"

# define RED_	"\x1b[31m"
# define GREEN_	"\x1b[32m"
# define YELLOW_	"\x1b[33m"
# define BLUE_	"\x1b[34m"
# define VIOLET_	"\x1b[35m"
# define CYAN_	"\x1b[36m"
# define RESET_	"\x1b[0m"

/**
 * Traverses the color chain backwards and multiplies each of its positions in
 * reverse order of traversal
 */
int		hex_to_color(char *color);
void	set_color_palet(int *a, void (*f)(int *, int, int), int p, int z_val);
void	*get_color_palette(int palette);
void	set_color_array(t_fdf *fdf);
int		sp_rgb(unsigned int r, unsigned int g, unsigned int b, unsigned int a);

#endif
