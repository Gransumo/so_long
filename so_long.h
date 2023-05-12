/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:44:16 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:44:17 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_SIZE 64
# include <mlx.h> 
# include "com_used.h"
# include "check_map/map.h"

typedef enum e_movetype
{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	ESC = 53
}			t_movetype;

typedef enum e_dirtype
{
	DIR_UP = 126,
	DIR_DOWN = 125,
	DIR_LEFT = 123,
	DIR_RIGHT = 124
}			t_dirtype;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}	t_tiletype;

typedef struct s_tile
{
	t_vector			position;
	t_tiletype			type;
	struct s_tile		*up;
	struct s_tile		*down;
	struct s_tile		*right;
	struct s_tile		*left;

}				t_tile;

typedef struct s_image
{
	void		*img;
	char		*addr;
	t_tiletype	type;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
	char		*path;
}				t_image;

typedef struct s_player
{
	t_tile		*tile;
	t_image		*img;

}				t_player;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_images
{
	t_image		wall;
	t_image		empty;
	t_image		collectable;
	t_image		exit;
	t_image		player_up;
	t_image		player_down;
	t_image		player_left;
	t_image		player_right;
}				t_images;

typedef struct s_game
{
	void		*mlx;
	t_window	mlx_win;
	t_tile		**tilemap;
	t_images	images;
	t_player	player;
	int			collects;
	int			moves;
	int			win;
}				t_game;

void		init_window(t_game *game);
void		init_images_menu(t_game *game);
int			finish_game(t_game *game);
void		ft_free_tilemap(t_tile	**tilemap);
int			key_input(int key, t_game *game);
void		set_image(t_game *game, t_tile *tile);
void		move_to(int key, t_game *game);

//void		print_map(t_game game);
#endif
