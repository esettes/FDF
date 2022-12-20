/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/20 01:35:28 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mem(t_fdf *fdf);
int		check_file_extension(char *file);

void	ft_leaks(void)
{
	system("leaks fdf");
}

int	main(int argc, char	*argv[])
{
	t_fdf	*fdf;

	if (argc < 3)
	{
		if (check_file_extension(argv[1]) == EXIT_FAILURE)
			exit (EXIT_FAILURE);
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		fdf->mlx = NULL;
		init_mlx(fdf, argv[1]);
		if (!fdf->mlx || !fdf->map.map)
			exit(EXIT_FAILURE);
		if (fdf->mlx)
			mlx_terminate(fdf->mlx);
		free_mem(fdf);
		return (EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	free_mem(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (fdf->map.map && fdf->map.colors && fdf->map.default_colors)
	{
		while (i < fdf->map.vertices.y)
		{
			free(fdf->map.map[i]);
			free(fdf->map.colors[i]);
			free(fdf->map.default_colors[i]);
			i++;
		}
		free(fdf->map.map);
		free(fdf->map.colors);
		free(fdf->map.default_colors);
	}
	free(fdf);
}
