## FDF
#### Draw maps in a interactable 3D mesh using MLX library.
<br>

<p align="center">
  <img height="300px" src="https://github.com/esettes/fdf-42/blob/main/src/maps/fdf_42.png" />
  <img height="300px" src="https://github.com/esettes/fdf-42/blob/main/src/maps/fdf_42_height.png" />
</p>

<p align="center">
  <img height="550px" src="https://github.com/esettes/fdf-42/blob/main/src/maps/fdf_new_himalaya_top_zoom.png" />
</p>

<p align="center">
  <img height="300px" src="https://github.com/esettes/-42-cursus-FDF/blob/main/src/maps/fdf_new_himalaya_top.png" />
  <img height="300px" src="https://github.com/esettes/fdf-42/blob/main/src/maps/fdf_himalaya_3d.png" />
</p>


<br><br>

### Comp environment

Mount temporary container which compiles program and exits.
````bash
docker run --rm  --mount type=bind,source=/home/,target=/home/ fdf:1.0 bash -c "cd $(makefile_dir) && make re"
````
