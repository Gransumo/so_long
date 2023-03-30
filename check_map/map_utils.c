
#include "../so_long.h"

void f_print_map(char **map);

void	ft_free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map);
}

t_vector	find_pp(char **map)
{
	t_vector	pp;

	pp.x = 0;
	pp.y = 0;
	while (map[pp.y])
	{
		while (map[pp.y][pp.x] && map[pp.y][pp.x] != 'P')
		{
			pp.x++;
			if (map[pp.y][pp.x] == 'P')
				return(pp);
		}
		pp.x = 0;
		pp.y++;
	}
	pp.x = 0;
	pp.y = 0;
	return (pp);
}

char	**chartab_dup(char	**map)
{
	char		**dup;
	t_vector	index;

	dup = malloc(sizeof(char *) * ft_charmap_linecounter(map) + 1);
	if (!dup)
		return (NULL);
	index.x = 0;
	while (map[index.x])
	{
		index.y = 0;
		dup[index.x] = malloc(ft_strlen(map[index.x]) + 1);
		if (!dup[index.x])
			return (null_error("ERROR TO MALLOC THE MAP COPY"));
		while (map[index.x][index.y] != '\0')
		{
			dup[index.x][index.y] = map[index.x][index.y];
			index.y++;
		}
		dup[index.x][index.y] = '\0';
		index.x++;
	}
	dup [index.x] = NULL;
	return (dup);
}

void	init_mapvars(t_map *map)
{
	map->len_x = ft_strlen_linemap(map->mapp[0]);
	map->n_lines = 0;
	map->n_C = 0;
	map->n_E = 0;
	map->n_P = 0;

	while (map->mapp[++map->n_lines] != NULL);
}