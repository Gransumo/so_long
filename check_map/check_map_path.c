#include "../so_long.h"

void f_print_map(char **map);

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

static void	ft_move(t_map *map_info, char c, t_vector *runner_pp)
{
	if (c == 'R')
	{
		check_type(map_info, map_info->mapp[runner_pp->y][runner_pp->x + 1]);
		map_info->mapp[runner_pp->y][runner_pp->x] = '1';
		runner_pp->x++;
		map_info->mapp[runner_pp->y][runner_pp->x] = 'P';
	}
	if (c == 'U')
	{
		check_type(map_info, map_info->mapp[runner_pp->y - 1][runner_pp->x]);
		map_info->mapp[runner_pp->y][runner_pp->x] = '1';
		runner_pp->y--;
		map_info->mapp[runner_pp->y][runner_pp->x] = 'P';
	}
	if (c == 'L')
	{
		check_type(map_info, map_info->mapp[runner_pp->y][runner_pp->x - 1]);
		map_info->mapp[runner_pp->y][runner_pp->x] = '1';
		runner_pp->x--;
		map_info->mapp[runner_pp->y][runner_pp->x] = 'P';
	}
	if (c == 'D')
	{
		check_type(map_info, map_info->mapp[runner_pp->y + 1][runner_pp->x]);
		map_info->mapp[runner_pp->y][runner_pp->x] = '1';
		runner_pp->y++;
		map_info->mapp[runner_pp->y][runner_pp->x] = 'P';
	}
}

static void	map_runner(t_map *map_info, t_vector runner_pp)
{
	if (map_info->mapp[runner_pp.y][runner_pp.x + 1] != '1') //verifico si es posible mover a la derecha
	{
		ft_move(map_info, 'R', &runner_pp);
		map_runner(map_info, runner_pp);
	}
	if (map_info->mapp[runner_pp.y - 1][runner_pp.x] != '1') //verifico si es posible mover arriba
	{
		ft_move(map_info, 'U', &runner_pp);
		map_runner(map_info, runner_pp);
	}
	if (map_info->mapp[runner_pp.y][runner_pp.x - 1] != '1')// verifico si es posible moverse a la izquierda
	{
		ft_move(map_info, 'L', &runner_pp);
		map_runner(map_info, runner_pp);
	}
	if (map_info->mapp[runner_pp.y + 1][runner_pp.x] != '1') // verificoo si es posible moverse abajo
	{
		ft_move(map_info, 'D', &runner_pp);
		map_runner(map_info, runner_pp);
	}
}


int	check_valid_path(t_map *map_info)
{
	t_vector runner_pp;

	runner_pp = find_pp(map_info->mapp);
	map_runner(map_info, runner_pp);
	return (check_final_values(map_info));
}
