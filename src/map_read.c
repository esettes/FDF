/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/08 18:48:04 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_fd_end(char *s);
void    set_z_points(t_fdf *fdf, char *raw_map);

/*void	set_map_info(t_fdf *fdf, char *raw_map)
{
	set_map_size(fdf, raw_map);
	set_z_points(fdf, raw_map);
	set_color_points(fdf, raw_map);
}

void	set_map_size(t_fdf *fdf, char *raw_map)
{
	t_iter	iter;
	int		fd;
	char	**lines;
	int		aux;
	int		trigger = TRUE;

	aux = 0;
	iter.i = 0;
	iter.j = 0;
	lines = malloc(sizeof(char *) * BUFFER_SIZE * 2);
	fd = open(raw_map, O_RDONLY);
	while (true)
	{
		lines[iter.i] = get_next_line(fd);
		iter.j += ft_count(lines[iter.i], ' ');
		if (trigger == TRUE)
		{
			trigger = FALSE;
			aux = iter.j;
		}
		if (check_fd_end(lines[iter.i]))
			break ;
		free(lines[iter.i]);
		iter.i++;
	}
	fdf->map.vertices = set_mtrx_size(aux, iter.i);
	fdf->map.map = malloc(sizeof(int *) * iter.j);
	fdf->map.colors = malloc(sizeof(int *) * iter.j);
	//printf("\nm->size->y: %f \n", fdf->map.vertices.y);
	printf("m->size->x: %f \n\n", fdf->map.vertices.x);
	close(fd);
}

void	set_z_points(t_fdf *fdf, char *raw_map)
{
	t_iter	iter;
	int		fd;
	char	*lines;
	int		aux;
	int		trigger = TRUE;

	aux = 0;
	iter.i = 0;
	iter.j = 0;
	fd = open(raw_map, O_RDONLY);
	while (true)
	{
		lines = get_next_line(fd);
		if (check_fd_end(lines))
			break ;
		set_line_z_points(fdf, lines, iter.i);
		free(lines);
		iter.i++;
	}
	close(fd);
}

void    set_line_z_points(t_fdf *fdf, char *str, int pos)
{
    char	**ch_aux;
    int		*z_point;
    t_iter  iter;
    t_iter  aux;

    iter.i = 0;
    iter.j = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    z_point = malloc(sizeof(int) * iter.j + 1);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        iter.i = ft_atoi(ch_aux[iter.j]);
		if (iter.i == "" && iter.i == NULL)
			break;
		*(z_point + iter.j) = iter.i;
		iter.j++;
    }
    fdf->map.map[pos] = z_point;
    if (ch_aux)
        free (ch_aux);
}

void	set_color_points(t_fdf *fdf, char *raw_map)
{
	t_iter	iter;
	int		fd;
	char	*lines;
	int		aux;
	int		trigger = TRUE;

	aux = 0;
	iter.i = 0;
	iter.j = 0;
	//lines = malloc(sizeof(char *) * BUFFER_SIZE * 2);
	fd = open(raw_map, O_RDONLY);
	while (true)
	{
		lines = get_next_line(fd);
		if (check_fd_end(lines))
			break ;
		set_line_color_points(fdf, lines, iter.i);
		free(lines);
		iter.i++;
	}
	close(fd);
}

void	set_line_color_points(t_fdf *fdf, char *str, int pos)
{
    char	**ch_aux;
    char    *extract;
    int     i_color;
    t_iter  iter;
    int     *int_color;

    iter.i = 0;
    iter.j = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    int_color = malloc(sizeof(int) * iter.j + 1);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        extract = ft_strchr(ch_aux[iter.j], 'x');
		iter.i = fdf->map.map[pos][iter.j];
		if (extract)
        {
            extract++;
            i_color = str_to_color(extract);
            *(int_color + iter.j) = i_color;
            extract = ""; 
        }
        else
        {
			// assign 0 value and call set_color palette when finish prepare map
			set_color_palette(int_color, get_color_palette(1), iter.j, iter.i);
            // if (iter.i >= 720)
            //     *(int_color + iter.j) = str_to_color("deddcc");
            // if (iter.i < 720 && iter.i >= 400)
            //     *(int_color + iter.j) = str_to_color("c56930");
            // if (iter.i < 400 && iter.i >= 200)
            //     *(int_color + iter.j) = str_to_color("c66a31");
            // if (iter.i < 200 && iter.i >= 90)
            //     *(int_color + iter.j) = str_to_color("d77b34");
            // if (iter.i < 90 && iter.i >= 50)
            //     *(int_color + iter.j) = str_to_color("e79b34");
            // if (iter.i < 50 && iter.i >= 35)
            //     *(int_color + iter.j) = str_to_color("e9cab3");
            // if (iter.i < 35 && iter.i >= 15)
            //     *(int_color + iter.j) = str_to_color("b5baa6");
            // if (iter.i < 15 && iter.i >= 0)
            //     *(int_color + iter.j) = str_to_color("b2b8a5");
            // if (iter.i < 0 && iter.i >= -5)
            //     *(int_color + iter.j) = str_to_color("3babbf"); //31a9ac
            // if (iter.i < -5 && iter.i >= -20)
            //     *(int_color + iter.j) = str_to_color("3aaaaf");
            // if (iter.i < -20 && iter.i >= -70)
            //     *(int_color + iter.j) = str_to_color("3ca9af");//3bb143
            // if (iter.i < -70 && iter.i >= -200)
            //     *(int_color + iter.j) = str_to_color("3a98ae");
            // if (iter.i < -200)// && iter.i >= -30)
            //     *(int_color + iter.j) = str_to_color("3797ad");

        }
		
		iter.j++;
    }
    fdf->map.colors[pos] = int_color;
    if (ch_aux)
        free (ch_aux);
}
*/


void	obtain_split_fd(int fd, t_map *m)
{
	char	**split_fd;
	t_iter	iter;
	int		aux;
	int		trigger = TRUE;
	t_iter	size_map;

	// size_map = get_map_size(fd);
	// printf("map size x: %i\n", size_map.j);
	// printf("map size y: %i\n", size_map.i);
	split_fd = malloc(sizeof(char *) * BUFFER_SIZE * 2);
	iter.i = 0;
	iter.j = 0;
	while (true)
	{
		split_fd[iter.i] = get_next_line(fd);	// i = y
		iter.j += ft_count(split_fd[iter.i], ' ');
		if (trigger == TRUE)
		{
			aux = iter.j;
			trigger = FALSE;
		}
		if (check_fd_end(split_fd[iter.i]))
			break ;
		iter.i++;
	}
	m->vertices = set_mtrx_size(aux, iter.i);
	m->map = malloc(sizeof(int *) * (m->vertices.x * m->vertices.y));//* iter.j);
	m->colors = malloc(sizeof(int *) * (m->vertices.x * m->vertices.y));//* iter.j);
	
	printf("Map x size: %f \n", m->vertices.x);
	printf("Map y size: %f \n\n", m->vertices.y);
	iter.i = 0;
	printf("\e[1;35mReading map...\e[0m\n");
	while (split_fd[iter.i])
	{
		if (iter.i % 50 == 0)
			printf("\e[2;35m%i lines processed...\e[0m\n", iter.i);
		obtain_z_and_color(m, split_fd[iter.i], iter.i);//, get_line_size(split_fd[iter.i]));
		iter.i++;
	}
	free(split_fd);
	set_default_color(m);
}

int	ft_count(char const *s, char c)
{
	int	cnt;
	size_t	bo;
	char	*a;

	cnt = 0;
	bo = 0;
	if (!s)
		return (0);
	a = (char *)s;
	if (!a)
		return (0);
	while (*a)
	{
		if (*a != c && bo == 0)
		{
			cnt++;
			bo = 1;
		}
		if (*a == c)
			bo = 0;
		a++;
	}
	return (cnt);
}

int	*str_to_int(char *str)
{
	char	**ch_aux;
	t_iter	iter;
	int		*int_mtrx;

	iter.j = 0;
	ch_aux = ft_split(str, ' ');
	while (ch_aux[iter.j])
		iter.j++;
	int_mtrx = malloc(sizeof(int) * iter.j);
	iter.j = 0;
	while (ch_aux[iter.j])
	{
		iter.i = ft_atoi(ch_aux[iter.j]);
		*(int_mtrx + iter.j) = iter.i;
		iter.j++;
	}
	free (str);
	free(ch_aux);
	return (int_mtrx);
}

int	check_fd_end(char *s)
{
	if (s == NULL || ft_strncmp(s, "\n", 1) == 0)// || 
		//ft_strncmp(s, " ", 1) == 0)
		return (TRUE);
	else
		return (FALSE);
}
