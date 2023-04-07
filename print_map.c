#include "so_long.h"

static t_image	init_image(void *mlx, char *path, t_tiletype type)
{
	t_image	img;
	
	img.type = type;
	img.img = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_size, &img.endian);

	return (img);
}

t_image	*init_images_menu(t_game *game)
{
	t_image	*images;

	images = malloc((sizeof(t_image) * 5) + 1);
	if (!images)
		return (null_error("ERROR ALLOCATING IMAGES POINTER"));
	images[0] = init_image(game->mlx, "images_files/empty.xpm",EMPTY);										//FALTA PONER PATH
	images[1] = init_image(game->mlx, "images_files/wall.xpm",WALL);
	images[2] = init_image(game->mlx, "images_files/collectable.xpm",COLLECTABLE);
	images[3] = init_image(game->mlx, "images_files/exit.xpm",EXIT);
	images[4] = init_image(game->mlx, "images_files/wall.xpm",PLAYER);
	images[5].type = 0;

	return (images);
}

static void	set_image(t_game *game, t_tile *tile)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (game->images[i].type == tile->type)
			mlx_put_image_to_window(game->mlx, game->mlx_win.reference, &game->images[i], tile->position.x * IMG_SIZE, tile->position.y * IMG_SIZE);
		i++;
	}
}

t_window	init_window(t_game *game)
{
	t_window	window;
	t_vector	int_vars;

	window.reference = mlx_new_window(game->mlx, game->mlx_win.size.x, game->mlx_win.size.y, "so_long");
	int_vars.x = 0;
	int_vars.y = 0;
	while (game->tilemap[int_vars.y])
	{
		int_vars.x = 0;
		while (game->tilemap[int_vars.y][int_vars.x].type != 0)
		{
			set_image(game, &game->tilemap[int_vars.y][int_vars.x]);
			int_vars.x++;
		}
		int_vars.y++;
	}
	return (window);
}
