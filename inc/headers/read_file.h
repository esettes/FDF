/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:07:08 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/06 22:04:36 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

# include "structs.h"

/*
 * Obtains each info necessary to run map visualization. Z points, heigh and
 * width and colors. This function unify obatin_split_fd(), get_z_points() and ...
 */
void	get_map_info(t_fdf *fdf);
char	**obtain_lines(int fd);
/**
 * Receives the previously opened fd, which is to be converted to a double
 * pointer array and stored in *m.
 * 
 * @param[in] fd File already open.
 * @param[in] m Struct where the conversion will be saved.
 */
void	obtain_split_fd(int fd, t_map *m);
/**
 * Count words of *s separated by 'c'
 * 
 * @return Number of words
 */
int		ft_count(char const *s, char c);
/**
 * Returns the conversion of *str to an integer array
 */
//int	*str_to_int(t_map *m, char *str, int pos);
/**
 * Returns the conversion of *str to an color array
 */
//char    *str_to_color(char *str);
/**
 * Call str_to_int() to get array with z values and str_to_color() to get
 * array with colors.
 */
void	obtain_z_and_color(t_map *m, char *str, int pos);
void	get_color_points(t_map *m, char *str, int pos);
void    get_z_points(t_map *m, char *str, int pos);

#endif