/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:45:17 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:45:19 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>
#include "../gnl/get_next_line.h"

//void f_print_map(char **map);

static int	is_empty(char *args)
{
	int		fd;
	char	c;

	fd = open (args, O_RDONLY);
	if (read (fd, &c, 1) == 0)
	{
		close(fd);
		return (0);
	}
	close (fd);
	return (1);
}

static int	line_counter(char *args)
{
	int		line_counter;
	int		fd;
	int		n_rchars;
	char	c;

	fd = open (args, O_RDONLY);
	if (fd < 0)
		return (error("MAP DOES NOT EXIST"));
	line_counter = 1;
	n_rchars = 1;
	while (n_rchars != 0)
	{
		n_rchars = read (fd, &c, 1);
		if (n_rchars < 0)
			return (error("FILE CANNOT BE READ"));
		if (c == '\n')
			line_counter++;
	}
	close (fd);
	return (line_counter);
}

static char	**alloc_map_size(int line_count)
{
	char	**map;

	map = malloc (sizeof(char *) * (line_count + 1));
	if (!map)
		return (null_error ("MAP CANNOT BE ALLOCATED"));
	map[line_count] = 0;
	return (map);
}

char	**read_map(char	*args)
{
	char	**map;
	int		fd;
	int		i;
	int		lines;

	if (is_empty(args) == 0)
		return (null_error("EMPTY FILE"));
	lines = line_counter (args);
	if (lines == 0)
		return (0);
	map = alloc_map_size (lines);
	if (map == NULL)
		return (NULL);
	i = 0;
	fd = open (args, O_RDONLY);
	if (fd < 0)
		return (null_error("MAP CANT BE OPEN"));
	while (i < lines)
		map[i++] = get_next_line (fd);
	map[i] = NULL;
	close (fd);
	return (map);
}
