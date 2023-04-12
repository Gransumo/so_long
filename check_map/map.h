/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:45:39 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:45:40 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../com_used.h"
# include "../so_long.h"

typedef struct s_map
{
	int			len_x;
	int			n_lines;
	int			n_c;
	int			n_e;
	int			n_p;
	char		**mapp;
}				t_map;

int			valid_file(int argc, char *argv);
char		**read_map(char	*args);
int			check_map_rules(char **map);
void		ft_free_map(char **map);
t_vector	find_pp(char **map);
char		**chartab_dup(char	**map);

#endif
