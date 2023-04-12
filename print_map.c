/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:44:01 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:44:04 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_image	init_image(void *mlx, char *path, t_tiletype type)
{
	t_image	img;

	img.type = type;
	img.path = path;
	img.img = mlx_xpm_file_to_image (mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr (img.img, &img.bpp, \
				&img.line_size, &img.endian);
	return (img);
}

void	set_image(t_game *game, t_tile *tile)
{
	if (tile->type == WALL)
		mlx_put_image_to_window (game->mlx, game->mlx_win.reference, \
		game->images.wall.img, tile->position.x, tile->position.y);
	else if (tile->type == EMPTY)
		mlx_put_image_to_window (game->mlx, game->mlx_win.reference, \
		game->images.empty.img, tile->position.x, tile->position.y);
	else if (tile->type == COLLECTABLE)
		mlx_put_image_to_window (game->mlx, game->mlx_win.reference, \
		game->images.collectable.img, tile->position.x, tile->position.y);
	else if (tile->type == EXIT)
		mlx_put_image_to_window (game->mlx, game->mlx_win.reference, \
		game->images.exit.img, tile->position.x, tile->position.y);
	else if (tile->type == PLAYER)
		mlx_put_image_to_window (game->mlx, game->mlx_win.reference, \
		game->player.img->img, tile->position.x, tile->position.y);
}

void	init_images_menu(t_game *game)
{
	game->images.empty = init_image (game->mlx, "images_files/empty.xpm", \
	EMPTY);
	game->images.wall = init_image (game->mlx, "images_files/wall.xpm", WALL);
	game->images.collectable = init_image (game->mlx, \
	"images_files/collectable.xpm", COLLECTABLE);
	game->images.exit = init_image (game->mlx, \
	"images_files/exit.xpm", EXIT);
	game->images.player_up = init_image (game->mlx, \
	"images_files/player_up.xpm", PLAYER);
	game->images.player_right = init_image (game->mlx, \
	"images_files/player_right.xpm", PLAYER);
	game->images.player_left = init_image (game->mlx, \
	"images_files/player_left.xpm", PLAYER);
	game->images.player_down = init_image (game->mlx, \
	"images_files/player_down.xpm", PLAYER);
	game->player.img = &game->images.player_up;
}

void	init_window(t_game *game)
{
	t_vector	int_vars;

	game->mlx_win.reference = mlx_new_window (game->mlx, \
	game->mlx_win.size.x, game->mlx_win.size.y, "so_long");
	int_vars.y = 0;
	while (game->tilemap[int_vars.y])
	{
		int_vars.x = 0;
		while (game->tilemap[int_vars.y][int_vars.x].type != 0)
		{
			set_image (game, &game->tilemap[int_vars.y][int_vars.x]);
			int_vars.x++;
		}
		int_vars.y++;
	}
}
