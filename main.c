#include "so_long.h"
t_tile		**tilemap_generator(char **map, t_game *game);

t_tile	**init_map(t_game *game, int argc, char **argv)
{
	t_tile	**tilemap;
	char	**map;

	if(valid_file(argc, argv[1]) == 0)
		return(NULL);
	map = read_map(argv[1]);
	if (!map)
		return (NULL);
	if (check_map_rules(map) == 0)
	{
		ft_free_map(map);
		return(NULL);
	}
	tilemap = tilemap_generator(map, game);
	ft_free_map(map);
	if (!tilemap)
		return (NULL);
	return(tilemap);
}

int	start_game(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = init_map(game, argc, argv);
	if(game->tilemap == NULL)
		return (0);
	return(1);
}

/* void print_map(t_game game)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (game.tilemap[y])
	{
		while (game.tilemap[y][x].type != 0)
		{
			ft_printf("%c", game.tilemap[y][x].type);
			x++;
		}
		ft_printf("\n");
		y++;
	}
} */



int main(int argc, char	**argv)
{
	t_game game;

	if(start_game(&game, argc, argv) == 0)
		return(0);
	//print_map(game);
}
