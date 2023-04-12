/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:41:55 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:41:58 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_tilemap(t_tile	**tilemap)
{
	int	i;

	i = 0;
	while (tilemap[i])
	{
		free(tilemap[i]);
		i++;
	}
	free(tilemap);
}

int	finish_game(t_game *game)
{
	ft_free_tilemap (game->tilemap);
	game->tilemap = NULL;
	exit (0);
}
