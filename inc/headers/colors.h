/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:50:04 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/05 19:45:57 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

int 	menu_rgb(int value);
/**
 * Returns an hex color from red (value < 0.1) , through green,
 *  to blue (value > 0.8) 
 */
int		rgba(int value);
int		get_trgb(int str);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		str_to_color_(char *color);
/**
 * Traverses the color chain backwards and multiplies each of its positions in 
 * reverse order of traversal
 */
int		str_to_color(char *color);
double	ft_percent(int start, int end, int current);
int		ft_gradient(int start, int end, double percent);
int		separate_sections(unsigned int r, unsigned int g, unsigned int b,  unsigned int a);

#endif