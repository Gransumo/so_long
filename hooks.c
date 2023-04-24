/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:42:32 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:42:34 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ch_dir(int key, t_game *game)
{
	if (key == DIR_UP || key == UP)
		game->player.img = &game->images.player_up;
	else if (key == DIR_DOWN || key == DOWN)
		game->player.img = &game->images.player_down;
	else if (key == DIR_LEFT || key == LEFT)
		game->player.img = &game->images.player_left;
	else if (key == DIR_RIGHT || key == RIGHT)
		game->player.img = &game->images.player_right;
	set_image(game, game->player.tile);
}

static int	check_move(t_game *game, t_tile *tile, int key)
{
	int	checker;

	checker = 1;
	if (tile->type == WALL)
		return (error("IMPOSSIBLE MOVE, THERE IS A WALL"));
	else if (tile->type == COLLECTABLE)
		game->collects--;
	else if (tile->type == EXIT)
	{
		if (game->collects == 0)
			finish_game(game);
		else
		{
			ch_dir(key, game);
			return (error("TO FINISH YOU HAVE TO GET ALL COLLECTABLES\n"));
		}
	}
	return (checker);
}

int	key_input(int key, t_game *game)
{
	int	checker;

	checker = 0;
	if (key == ESC)
		finish_game(game);
	else if ((key >= LEFT && key <= RIGHT) || key == UP)
	{
		if (key == UP)
			checker = check_move(game, game->player.tile->up, key);
		else if (key == DOWN)
			checker = check_move(game, game->player.tile->down, key);
		else if (key == RIGHT)
			checker = check_move(game, game->player.tile->right, key);
		else if (key == LEFT)
			checker = check_move(game, game->player.tile->left, key);
		if (checker != 0)
			move_to(key, game);
	}
	else if (key >= DIR_LEFT && key <= DIR_UP)
		ch_dir(key, game);
	else
		ft_printf("\nINVALID KEY\n");
	return (0);
}
