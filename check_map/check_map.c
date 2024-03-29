/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:44:48 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:44:49 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int			check_path(t_map *map_info);
void		init_mapvars(t_map *map);

static int	first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (i);
}

static int	check_map_values(t_map *map_info)
{
	if (map_info->n_c < 1)
		return (error ("COLLECTABLE NOT FOUND"));
	if (map_info->n_e < 1)
		return (error ("EXIT NOT FOUND"));
	if (map_info->n_e > 1)
		return (error ("THERE CAN ONLY ONE EXIT CHARACTER"));
	if (map_info->n_p < 1)
		return (error ("PLAYER NOT FOUND"));
	if (map_info->n_p > 1)
		return (error ("THERE CAN ONLY BE ONE PLAYER"));
	return (1);
}

static int	check_line(char	*line, t_map *map_info, int index)
{
	int	i;

	if ((index == 0 || index == map_info->n_lines - 1) \
		&& first_last_line (line) == 0)
		return (error ("THE MAP HAS TO BE SURRONDER BY WALLS"));
	if (ft_strlen_linemap (line) != map_info->len_x)
		return (error ("THE MAP HAS TO BE RECTANGULAR"));
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if ((i == 0 || i == map_info->len_x - 1) && line[i] != '1')
			return (error ("THE MAP HAS TO BE SURRONDER BY WALLS"));
		if (line[i] == 'C')
			map_info->n_c++;
		else if (line[i] == 'E')
			map_info->n_e++;
		else if (line[i] == 'P')
			map_info->n_p++;
		else if (!ft_strchr("CEP10", line[i]))
			return (error ("INVALID CHARACTER HAS BEEN FOUND ON THE MAP"));
		i++;
	}
	return (1);
}

int	valid_file(int argc, char *argv)
{
	if (argc == 1)
		return (error ("NO ARGS"));
	if (argc > 2)
		print_warning ("ONLY WILL BE USED THE FIRST ARGUMENT");
	if (ft_strcmp_end (argv, ".ber") == 0)
		return (error ("THE FILE SHOULD BE A .ber FILE"));
	return (1);
}

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

int	check_map_rules(char **map)
{
	t_map	map_info;
	int		i;

	i = 0;
	map_info.mapp = map;
	init_mapvars (&map_info);
	while (map_info.mapp[i] != NULL)
	{
		if (check_line (map_info.mapp[i], &map_info, i) == 0)
		{
			ft_free_map (map_info.mapp);
			return (0);
		}
		i++;
	}
	if (check_map_values (&map_info) == 0 || check_path (&map_info) == 0)
	{
		ft_free_map (map_info.mapp);
		return (0);
	}
	ft_free_map (map);
	return (1);
}
