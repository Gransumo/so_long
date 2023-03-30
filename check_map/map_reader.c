#include "../so_long.h"
#include <fcntl.h>
#include "../gnl/get_next_line.h"

void f_print_map(char **map);

static size_t	line_counter(char	*args)
{
	size_t	line_counter;
	int		fd;
	int		n_rchars;
	char	c;

	fd = open(args, O_RDONLY);
	if(fd < 0)
		return (0);
	line_counter = 1;
	n_rchars = 1;
	while (n_rchars != 0)
	{
		n_rchars = read(fd, &c, 1);
		if (n_rchars < 0)
			return (0);
		if(c == '\n')
			line_counter++;
	}
	close (fd);
	return (line_counter);
}

static char	**alloc_map_size(char *args)
{
	char	**map;
	size_t	line_count;

	line_count = line_counter(args);
	if(line_count == 0)
		return(null_error("FILE CANNOT BE OPEN OR READ, MAYBE THE FILE CANNOT BE FOUND OR DONT EXIST"));
	map = malloc(sizeof(char *) * (line_count + 1));
	if (map == NULL)
		return(null_error("MAP CANNOT BE ALLOCATED"));
	map[line_count] = 0;
	return (map);
}

char	**read_map(char	*args)
{
	char	**map;
	int		fd;
	int		i;
	int		lines;

	map = alloc_map_size(args);
	if(map == NULL)
		return (NULL);
	lines = line_counter(args);
	i = 0;
	fd = open(args, O_RDONLY);
	while (i < lines)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}
