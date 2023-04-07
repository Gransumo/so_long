
#ifndef	SO_LONG_H
# define SO_LONG_H
# define IMG_SIZE 64
# include <mlx.h> 
# include "com_used.h"
# include "check_map/map.h"

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}	t_tiletype;

typedef	struct	s_tile
{
	t_vector	position;
	t_tiletype	type;
	struct s_tile		*up;
	struct s_tile		*down;
	struct s_tile		*right;
	struct s_tile		*left;

}				t_tile;

typedef struct	s_player
{
	t_tile		*tile;

}				t_player;

typedef struct	s_image
{
	void		*img;
	char		*addr;
	t_tiletype	type;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}				t_image;

typedef	struct	s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct	s_game
{
	void		*mlx;
	t_window	mlx_win;
	t_tile		**tilemap;
	t_image		*images;
	t_player	player;
	int			collects;
	int			moves;
}				t_game;


t_window	init_window(t_game *game);
t_image		*init_images_menu(t_game *game);
/* t_image		ft_new_img(void	*mlx, char *path);
t_window	ft_new_window(void *mlx, int widht, int height, char *name); */

#endif