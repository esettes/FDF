# Fils de Fer
This project is about creating a simplified graphic wireframe (fils de fer) representation of a relief landscape linking various points(x, y, z) via segments.

<p align="center">
  <img height="280px" src="https://github.com/esettes/-42-cursus-FDF/blob/main/src/maps/fdf_new_himalaya_top.png" />
  <img height="280px" src="https://github.com/esettes/fdf-42/blob/main/src/maps/fdf_himalaya_3d.png" />
</p>

<br>

## Contents
- [Introduction](#Introduction)
- [Challenge](#Challenge)
  - [Steps](#Steps)
- [Launch](#Launch)
- [Screenshots](#Screenshots)
- [Build environment](#Environment)
 
<a name='Introduction'></a>
 
## Introduction
  Here I learn how to place points in space, how to join them with segments and how to observe the scene from a particular point of view.
  
  It works with the graphic library miniLibX. This library was developed internally and includes the minimum necessary to open a window, light a pixel and deal with events linked to this window: keyboard and mouse. In this case I've used the [MLX42](https://github.com/codam-coding-college/MLX42) library, developed by Codam's colleagues (42), similar to the original but updated and documented.
  
  
The coordinates of the landscape which must be represented are stored in a file passed as a parameter to the program. 

<details>
<summary> Example file parameter: 👈 </summary>
  
````
$>cat 42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  10 10 0  0  10 10 0  0  0  10 10 10 10 10 0  0  0
0  0  10 10 0  0  10 10 0  0  0  0  0  0  0  10 10 0  0
0  0  10 10 0  0  10 10 0  0  0  0  0  0  0  10 10 0  0
0  0  10 10 10 10 10 10 0  0  0  0  10 10 10 10 0  0  0
0  0  0  10 10 10 10 10 0  0  0  10 10 0  0  0  0  0  0
0  0  0  0  0  0  10 10 0  0  0  10 10 0  0  0  0  0  0
0  0  0  0  0  0  10 10 0  0  0  10 10 10 10 10 10 0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
$>
````
Each number corresponds to a point in space.
> Horizontal position corresponds to axis(x).
  
> Vertical position corresponds to ordinate(y).
  
> The value corresponds to altitude.
  
</details>


<details>
<summary> Executing program with this file, we should see something like this: 👈 </summary>

<p align="center">
  <img height="320px" src="https://github.com/esettes/fdf-42/blob/main/src/maps/fdf_42.png" />
  <img height="320px" src="https://github.com/esettes/fdf-42/blob/main/src/maps/fdf_42_height.png" />
</p>

</details>

<a name='Challenge'></a>
 
## Challenge

 Allowed functions and libraries:
- open, read, write, close
- malloc, free
- perror, strerror
- exit
- math library.
- miniLibX library.

###### The use of any other function explicitly not allowed its forbidden. 

<a name='Steps'></a>

## Steps
### 1. Print a paralell mesh. Bresenham's line algorithm.
The [Bresenham's algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) consists of, given an initial and a final coordinate, it obtains all the intermediate coordinates from one point to the other, until forming a line. This algorithm whit pixel_put() function allows me draw the wireframe.

After several Bresenham's discarded algorithms, in the end this was that allowed me the scalability of the program.

<p  align="center">
  <img align="left" height="200px" src="https://user-images.githubusercontent.com/65050547/192756047-ebac39a0-8f8c-4aad-97f5-ee7753bbbc0d.png" />
  <img align="center" height="200px" src="https://user-images.githubusercontent.com/65050547/192756437-04bcf327-9317-4466-a56e-c57fca3ed649.png" />
  <img align="right" height="200px" src="https://user-images.githubusercontent.com/65050547/192780285-e7a93b17-d327-4c8e-bcb7-b0afc1dda722.png" />
</p>


...

### 2. Print isometric mesh.

The minilibX is not intended to represent 3D graphics, so the depth(z-axis) is obtained by modifying x and y coordinates.
My biggest problem when I started with isometric view was dealing with sines and cosines, since I had never worked with it.

![iso](https://user-images.githubusercontent.com/65050547/192663608-fba6d3e4-ee96-4de9-acb8-f498eef87eee.png)

````c
void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth)
{
    float	z_zoom;

    z_zoom = 0.5;
    start->x = (start->x - start->y) * (cos(45) * 1);
    start->y = (start->x + start->y) * (sin(45) * z_zoom) - (depth.z * z_zoom
        * (fdf->control.zoom * 0.2));
    end->x = (end->x - end->y) * (cos(45) * 1);
    end->y = (end->x + end->y) * (sin(45) * z_zoom) - (depth.z1 * z_zoom
        * (fdf->control.zoom * 0.2));
    (void)fdf;
}
````

### 3. Obtain and draw map height.


### 4. Obtain and parse colors.






<br><br>
<a name='Environment'></a>

### Build environment

Mount temporary container which <mark>compiles program</mark> and exits.
````bash
docker run --rm  --mount type=bind,source=/home/,target=/home/ fdf:1.0 bash -c "cd $(makefile_dir) && make re"
````
