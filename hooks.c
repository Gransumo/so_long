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

void	win_game(t_game *game);

static int	check_move(t_game *game, t_tile *tile)
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
			return (error("TO FINISH YOU HAVE TO GET ALL COLLECTABLE\n"));
	}
	return (checker);
}

void	ch_dir(int key, t_game *game)
{
	if (key == DIR_UP || key == UP)
		game->player.img->img = game->images.player_up.img;
	else if (key == DIR_DOWN || key == DOWN)
		game->player.img->img = game->images.player_down.img;
	else if (key == DIR_LEFT || key == LEFT)
		game->player.img->img = game->images.player_left.img;
	else if (key == DIR_RIGHT || key == RIGHT)
		game->player.img->img = game->images.player_right.img;
	set_image(game, game->player.tile);
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
			checker = check_move(game, game->player.tile->up);
		else if (key == DOWN)
			checker = check_move(game, game->player.tile->down);
		else if (key == RIGHT)
			checker = check_move(game, game->player.tile->right);
		else if (key == LEFT)
			checker = check_move(game, game->player.tile->left);
		if (checker != 0)
			move_to(key, game);
	}
	else if (key >= DIR_LEFT && key <= DIR_UP)
		ch_dir(key, game);
	else
		ft_printf("\nTECLA INVALIDA\n");
	return (0);
}
