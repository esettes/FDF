/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:24:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/20 03:38:21 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include "macros.h"
#include "colors.h"
#include "mlx_utils.h"
#include "read_file.h"
#include <fcntl.h>
#include "map_utils.h"
#include "draw.h"

t_controls	set_init_controls(t_controls *control);
static void	open_fd(t_fdf *fdf, char *raw_map);
static void	init_program(t_fdf *fdf);

void	init_mlx(t_fdf *fdf, char *raw_map)
{
	fdf->control = set_init_controls(&fdf->control);
	open_fd(fdf, raw_map);
	if (obtain_split_fd(fdf->fd, &fdf->map) == EXIT_FAILURE)
	{
		close(fdf->fd);
		return ;
	}
	close(fdf->fd);
	if (!fdf->map.map)
	{
		ft_putendl_fd(RED_, "Error: Can't obtain map info.", 1);
		exit(EXIT_FAILURE);
		return ;
	}
	fdf->mlx = mlx_init(WIDTH - 100, HEIGHT - 50, "Wire-frame (fdf)", true);
	if (!fdf->mlx)
	{
		ft_putendl_fd(RED_, "Error: Can't initialize mlx.", 1);
		exit(EXIT_FAILURE);
		return ;
	}
	init_program(fdf);
}

static void	init_program(t_fdf *fdf)
{
	create_image(fdf, 0);
	draw_menu(fdf);
	draw_menu_box(fdf);
	draw_image(fdf);
	loop_fdf(fdf);
}

t_controls	set_init_controls(t_controls *control)
{
	control->palette = 0;
	control->zoom = 3;
	control->rot_angle = 0;
	control->points_resolution = ADDIT_STEPS;
	control->height = 3;
	control->vert = 1;
	control->horiz = 1;
	control->perspective = ISOMETRIC;
	return (*control);
}

static void	open_fd(t_fdf *fdf, char *raw_map)
{
	fdf->fd = open(raw_map, O_RDONLY);
	if (fdf->fd < 0)
	{
		ft_putendl_fd(RED_, "Error: File not found.", 1);
		exit(EXIT_FAILURE);
		return ;
	}
}

int	check_file_extension(char *file)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*ext;

	len = ft_strlen(file);
	i = len - 4;
	j = 0;
	while (j < i)
	{
		file++;
		j++;
	}
	ext = ft_strnstr(file, ".fdf", 4);
	if (ext == NULL)
	{
		ft_putendl_fd(RED_, "Error: Invalid file extension.", 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
