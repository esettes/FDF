#include "fdf.h"

void    get_z_points(t_map *m, char *str, int pos)
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
		*(z_point + iter.j) = iter.i;
		iter.j++;
    }
    m->map[pos] = z_point;
    if (ch_aux)
        free (ch_aux);
    free (str);
}

void	get_color_points(t_map *m, char *str, int pos)
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
        //extract = ft_strnstr_after(ch_aux[iter.j], "x", 5);
        extract = ft_strchr(ch_aux[iter.j], 'x');
        // si la extraccion es distinta de lo que ya hay en la cadena entonces calcular, sino continuar
        if (extract)// && extract != "")
        {
            extract++;
            i_color = str_to_color(extract);
            *(int_color + iter.j) = i_color;
            extract = ""; 
        }
        else
          *(int_color + iter.j) = 255;
		iter.j++;
    }
    m->colors[pos] = int_color;
    if (ch_aux)
        free (ch_aux);
    free (str);
}

int    get_line_size(char *str)
{
    char	**ch_aux;
    int     i;

    i = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[i])
        i++;
    free (ch_aux);
    return (i);
}

void	obtain_z_and_color(t_map *m, char *str, int pos)//, int size)
{
    char	**ch_aux;
    char    *extract;
    int     i_color;
    //int		int_mtrx[size];
    int		*int_mtrx;
    t_iter  iter;
    //int     int_color[size];
    int     *int_color;

    iter.i = 0;
    iter.j = 0;
    //printf("size: %d\n\n", size);
    //count_line_elements(str, &aux.j);
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
	  	iter.j++;
    int_mtrx = malloc(sizeof(int) * iter.j);
    int_color = malloc(sizeof(int) * iter.j);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        extract = ft_strchr(ch_aux[iter.j], 'x');
        iter.i = ft_atoi(ch_aux[iter.j]);
		//*(int_mtrx + iter.j) = iter.i;
        int_mtrx[iter.j] = iter.i;
        if (extract)// && extract != "")
        {
            extract++;
            i_color = str_to_color(extract);
            int_color[iter.j] = i_color;
            //*(int_color + iter.j) = i_color;
            extract = ""; 
        }
        else if (!extract)
        {
            set_color_palette(int_color, get_color_palette(1), iter.j, iter.i);
        }
		iter.j++;
    }
    m->colors[pos] = int_color;
    m->map[pos] = int_mtrx;
    //free (int_mtrx);
    if (ch_aux)
        free (ch_aux);
    free (str);
}

// funcion que detecta altura de la z y devuelve un color acorde
//unsigned int    color_for_z(int z)