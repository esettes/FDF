#include "fdf.h"

void	*get_color_palette(int palette)
{
	void (*ptr)(int *, int, int);

	if (palette == 0)
		ptr = &palette_default;
	if (palette == 1)
		ptr = &palette_test;
    if (palette == 2)
		ptr = &palette_gamma;
	return ptr;
}

void	set_color_palette(int *arr, void (*f)(int *, int, int), int pos, int z_value) //t_fdf *fdf, 
{
	f(arr, pos, z_value);
}

void    set_color_array(t_fdf *fdf)
{
    int i;
    int j;
    int *arr;

    i = 0;
    while (i < fdf->map.vertices.y)
    {
        j = 0;
        while (j < fdf->map.vertices.x)
        {
            set_color_palette(fdf->map.colors[i], 
                get_color_palette(fdf->control.palette), j, fdf->map.map[i][j]);
            j++;
        }
        i++;
    }
    //return (TRUE);
    //fdf->map.colors = arr;
}