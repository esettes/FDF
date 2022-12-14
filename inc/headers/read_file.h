/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:07:08 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/19 00:29:58 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

# include "structs.h"

/**
 * Receives the previously opened fd, which is to be converted to a double
 * pointer array and stored in *m.
 * 
 * @param[in] fd File already open.
 * @param[in] m Struct where the conversion will be saved.
 */
int		obtain_split_fd(int fd, t_map *m);
/**
 * Count words of *s separated by 'c'
 * 
 * @return Number of words
 */
int		ft_count(char const *s, char c);
/**
 * Call str_to_int() to get array with z values and str_to_color() to get
 * array with colors.
 */
int		obtain_z_and_color(t_map *m, char **str, int pos);
void	set_default_color(t_map *m);
void	set_color_to_arr(char *extract, int i, int *arr);
void	set_color_for_item(char *extract, int *arr_color, t_iter iter);
void	get_color_and_integer(char **extr, char **ch, t_iter *iter, int *mtrx);
void	free_strings(char **ch_aux, char *str);
int		*str_to_int(char *str);
int		ft_count(char const *s, char c);
size_t	count_spaces(const char *s);
int		check_map_size(char **split_fd, int pos);
int		check_valid_map(char **map, t_vec2 size);
void	free_bronken_map(char **str, int len);

#endif
