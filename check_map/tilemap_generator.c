#include "map.h"

t_tile	**alloc_tilemap(char **map)
{
	t_tile	**tilemap;
	int		i;

	tilemap = malloc(sizeof(t_tile *) * ft_charmap_linecounter(map) + 1);// !!CAMBIAR FUNCION LINE_COUNTER
	if (!tilemap)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		tilemap[i] = malloc(sizeof(t_tile) * ft_strlen_linemap(map[i]) + 1);
		if (!tilemap)
		{
			while (i >= 0)
				free(tilemap[i--]); //SI FALLA ALGUN LEAK REVISAR ESTA LINEA
			free(tilemap);
			return(NULL);
		}
		i++;
	}
	return (tilemap);	
}

t_tiletype	set_tiletype(char c)
{
	t_tiletype	tile;
	
	if (c == '1')
		tile = WALL;
	if (c == '0')
		tile = EMPTY;
	if (c == 'P')
		tile = PLAYER;
	if (c == 'E')
		tile = EXIT;
	if (c == 'C')
		tile = COLLECTABLE;
	return (tile);
}

void	set_tilevars(t_tile **tilemap, int y, int x)
{
	tilemap[y][x].position.y = y * IMG_SIZE;
	tilemap[y][x].position.x = x * IMG_SIZE;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (&tilemap[y + 1][x] != NULL)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

void	set_gamevars(t_game *game, t_tile *tile)
{
	if (tile->type == PLAYER)
		game->player.tile = tile;
	else if (tile->type == COLLECTABLE)
		game->collects++;
}

t_tile	**tilemap_generator(char **map, t_game *game)
{
	t_tile	**tilemap;
	int		x;
	int		y;
	tilemap = alloc_tilemap(map); //RESERVO MEMORIA PARA EL MAPA DE MOSAICOS
	if (!tilemap)
		return (null_error("MALLOC ERROR ON ALLOC TILEMAP"));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			tilemap[y][x].type = set_tiletype(map[y][x]);
			set_tilevars(tilemap, y, x);
			set_gamevars(game, &tilemap[y][x]);
			x++;
		}
		tilemap[y][x].type = 0;
		y++;
	}
	tilemap[y] = NULL;
	game->mlx_win.size.x = x * IMG_SIZE;
	game->mlx_win.size.y = y * IMG_SIZE;
	return(tilemap);
}
