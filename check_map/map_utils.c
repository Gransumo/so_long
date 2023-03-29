
#include "../so_long.h"

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