
#ifndef MAP_H
# define MAP_H
#include "../com_used.h"
#include "../so_long.h"

typedef struct	s_map
{
	int			len_x;
	int			n_lines;
	int			n_C;
	int			n_E;
	int			n_P;
	char		**mapp;
}				t_map;

int			valid_file(int argc, char *argv);
char		**read_map(char	*args);
int			check_map_rules(char **map);
void		ft_free_map(char **map);
t_vector	find_pp(char **map);

#endif