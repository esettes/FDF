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

// void	lk(void)
// {
// 	system("leaks fdf");
// }
void	ft_leaks()
{
	system("leaks fdf");
}

int	main(int argc, char	*argv[])
{
	t_fdf	*fdf;
	//atexit(&ft_leaks);
	if (argv[0])
		printf("ok");
	// atexit(lk);
	if (argc < 3)
	{
		printf("\norigin offset X: %d\n", X_ORIGIN_OFF);
		printf("origin offset Y: %d\n", Y_ORIGIN_OFF);
		printf("width: %d\n", WIDTH);
		printf("HEIGHT: %d\n\n", HEIGHT);
		
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
//		fdf->fd = open("src/maps/test_maps/japan.fdf", O_RDONLY);
		fdf->fd = open(argv[1], O_RDONLY);
		
		if (fdf->fd <= 0)
		{
			exit(EXIT_FAILURE);
			return (EXIT_FAILURE);
		}
		init_mlx(fdf);
		if (!fdf->mlx || !fdf->mtrx.mtrx)
			exit(EXIT_FAILURE);
		close(fdf->fd);
		return (EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
