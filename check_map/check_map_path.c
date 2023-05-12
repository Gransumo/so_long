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

static int	check_type(t_map *v_map, char c)
{
	if (c == 'E')
		v_map->n_e = 0;
	else if (c == '0')
		return (1);
	else if (c == 'C')
	{
		v_map->n_c--;
		return (1);
	}
	return (0);
}

static t_vector	ft_move(t_map *v_map, char c, t_vector r_pp)
{
	v_map->mapp[r_pp.y][r_pp.x] = '1';
	if (c == 'R')
		r_pp.x++;
	else if (c == 'U')
		r_pp.y--;
	else if (c == 'L')
		r_pp.x--;
	else if (c == 'D')
		r_pp.y++;
	v_map->mapp[r_pp.y][r_pp.x] = 'P';
	return (r_pp);
}

static int	check_final_values(t_map *v_map)
{
	if (v_map->n_c != 0)
		return (error ("IT IS NOT POSSIBLE TO GET ALL COLLECTABLES"));
	if (v_map->n_e != 0)
		return (error ("IT IS NOT POSSIBLE TO REACH THE EXIT"));
	return (1);
}

static void	map_runner(t_map *v_map, t_vector r_pp)
{
	if (check_type (v_map, v_map->mapp[r_pp.y][r_pp.x + 1]) != 0)
		map_runner (v_map, ft_move (v_map, 'R', r_pp));
	if (check_type (v_map, v_map->mapp[r_pp.y - 1][r_pp.x]) != 0)
		map_runner (v_map, ft_move (v_map, 'U', r_pp));
	if (check_type (v_map, v_map->mapp[r_pp.y][r_pp.x - 1]) != 0)
		map_runner (v_map, ft_move (v_map, 'L', r_pp));
	if (check_type (v_map, v_map->mapp[r_pp.y + 1][r_pp.x]) != 0)
		map_runner (v_map, ft_move (v_map, 'D', r_pp));
}

int	check_path(t_map *v_map)
{
	t_vector	r_pp;

	r_pp = find_pp (v_map->mapp);
	map_runner (v_map, r_pp);
	return (check_final_values (v_map));
}
//f_print_map(v_map->mapp);
