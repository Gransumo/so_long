#include "../so_long.h"

static void	check_type(t_map *map_info, char c)
{
	if (c == 'C')
		map_info->n_C--;
	if(c == 'E')
		map_info->n_E = 0;
}

static int	check_final_values(t_map *map_info)
{
	if (map_info->n_C != 0)
		return (error("IT IS NOT POSSIBLE TO GET ALL COLLECTABLES"));
	if (map_info->n_E != 0)
		return (error("IT IS NOT POSSIBLE TO REACH THE EXIT"));
	return (1);
}

static void	ft_move(t_map *map_info, char c)
{
	if (c == 'R')
	{
		check_type(map_info, map_info->mapp[map_info->pp.y][map_info->pp.x + 1]);
		map_info->mapp[map_info->pp.y][map_info->pp.x] = '1';
		map_info->pp.x++;
	}
	else if (c == 'U')
	{
		check_type(map_info, map_info->mapp[map_info->pp.y + 1][map_info->pp.x]);
		map_info->mapp[map_info->pp.y][map_info->pp.x] = '1';
		map_info->pp.y++;
	}
	else if (c == 'L')
	{
		check_type(map_info, map_info->mapp[map_info->pp.y][map_info->pp.x - 1]);
		map_info->mapp[map_info->pp.y][map_info->pp.x] = '1';
		map_info->pp.x--;
	}
	else if (c == 'D')
	{
		check_type(map_info, map_info->mapp[map_info->pp.y - 1][map_info->pp.x]);
		map_info->mapp[map_info->pp.y][map_info->pp.x] = '1';
		map_info->pp.y--;
	}
}

static void	map_runner(t_map *map_info)
{
	if (map_info->mapp[map_info->pp.y][map_info->pp.x + 1] != '1') //verifico si es posible mover a la derecha
	{
		ft_move(map_info, 'R');
		map_runner(map_info);
	}
	if (map_info->mapp[map_info->pp.y - 1][map_info->pp.x] != '1') //verifico si es posible mover arriba
	{
		ft_move(map_info, 'U');
		map_runner(map_info);
	}
	if (map_info->mapp[map_info->pp.y][map_info->pp.x - 1] != '1')// verifico si es posible moverse a la izquierda
	{
		ft_move(map_info, 'L');
		map_runner(map_info);
	}
	if (map_info->mapp[map_info->pp.y + 1][map_info->pp.x] != '1') // verificoo si es posible moverse abajo
	{
		ft_move(map_info, 'D');
		map_runner(map_info);
	}
}


int	check_valid_path(t_map *map_info)
{
	map_runner(map_info);
	return (check_final_values(map_info));
}
