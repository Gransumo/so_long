/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:44:56 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:44:57 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/* void	f_print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			ft_printf ("%c", map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	ft_printf ("\n\n");
} */

static void	check_type(t_map *map_info, char c)
{
	if (c == 'C')
		map_info->n_c--;
	if (c == 'E')
		map_info->n_e = 0;
}

static int	check_final_values(t_map *map_info)
{
	if (map_info->n_c != 0)
		return (error ("IT IS NOT POSSIBLE TO GET ALL COLLECTABLES"));
	if (map_info->n_e != 0)
		return (error ("IT IS NOT POSSIBLE TO REACH THE EXIT"));
	return (1);
}

static t_vector	ft_move(t_map *map_info, char c, t_vector runner_pp)
{
	if (c == 'R')
	{	
		map_info->mapp[runner_pp.y][runner_pp.x] = '1';
		runner_pp.x++;
		map_info->mapp[runner_pp.y][runner_pp.x] = 'P';
	}
	if (c == 'U')
	{	
		map_info->mapp[runner_pp.y][runner_pp.x] = '1';
		runner_pp.y--;
		map_info->mapp[runner_pp.y][runner_pp.x] = 'P';
	}
	if (c == 'L')
	{
		map_info->mapp[runner_pp.y][runner_pp.x] = '1';
		runner_pp.x--;
		map_info->mapp[runner_pp.y][runner_pp.x] = 'P';
	}
	if (c == 'D')
	{
		map_info->mapp[runner_pp.y][runner_pp.x] = '1';
		runner_pp.y++;
		map_info->mapp[runner_pp.y][runner_pp.x] = 'P';
	}
	return (runner_pp);
}

static void	map_runner(t_map *map_info, t_vector runner_pp)
{
	if (map_info->mapp[runner_pp.y][runner_pp.x + 1] != '1')
	{
		check_type (map_info, map_info->mapp[runner_pp.y][runner_pp.x + 1]);
		map_runner (map_info, ft_move (map_info, 'R', runner_pp));
	}
	if (map_info->mapp[runner_pp.y - 1][runner_pp.x] != '1')
	{
		check_type (map_info, map_info->mapp[runner_pp.y - 1][runner_pp.x]);
		map_runner (map_info, ft_move (map_info, 'U', runner_pp));
	}
	if (map_info->mapp[runner_pp.y][runner_pp.x - 1] != '1')
	{
		check_type (map_info, map_info->mapp[runner_pp.y][runner_pp.x - 1]);
		map_runner (map_info, ft_move (map_info, 'L', runner_pp));
	}
	if (map_info->mapp[runner_pp.y + 1][runner_pp.x] != '1')
	{
		check_type (map_info, map_info->mapp[runner_pp.y + 1][runner_pp.x]);
		map_runner (map_info, ft_move (map_info, 'D', runner_pp));
	}
}

//f_print_map(map_info->mapp);
int	check_path(t_map *map_info)
{
	t_vector	runner_pp;

	runner_pp = find_pp (map_info->mapp);
	map_runner (map_info, runner_pp);
	return (check_final_values (map_info));
}
