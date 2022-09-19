/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/12 19:59:02 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mem(t_fdf *fdf);

void	ft_leaks()
{
	system("leaks fdf");
}

int	main(int argc, char	*argv[])
{
	t_fdf	*fdf;
	//atexit(&ft_leaks);
	if (argc < 3)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		//fdf->fd = open(argv[1], O_RDONLY);
		init_mlx(fdf, argv[1]);
		if (!fdf->mlx || !fdf->map.map)
			exit(EXIT_FAILURE);
		mlx_terminate(fdf->mlx);
		free_mem(fdf);
		return (EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	free_mem(t_fdf *fdf)
{
	int i;

	i = 0;
	if (fdf->map.map && fdf->map.colors && fdf->map.default_colors)
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
	free(fdf);
}