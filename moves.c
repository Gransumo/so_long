/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:43:28 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:43:29 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ch_dir(int key, t_game *game);

static void	up_move(t_game *game)
{
	ft_printf("PLAYER MOVE UP\nMISSING COLLECTABLES: %i\n", game->collects);
	game->player.tile->type = EMPTY;
	game->player.tile = game->player.tile->up;
	game->player.tile->type = PLAYER;
	set_image(game, game->player.tile->down);
	set_image(game, game->player.tile);
}

static void	down_move(t_game *game)
{
	ft_printf("PLAYER MOVE DOWN\nMISSING COLLECTABLES: %i\n", game->collects);
	game->player.tile->type = EMPTY;
	game->player.tile = game->player.tile->down;
	game->player.tile->type = PLAYER;
	set_image(game, game->player.tile->up);
	set_image(game, game->player.tile);
}

static void	right_move(t_game *game)
{
	ft_printf("PLAYER MOVE RIGHT\nMISSING COLLECTABLES: %i\n", game->collects);
	game->player.tile->type = EMPTY;
	game->player.tile = game->player.tile->right;
	game->player.tile->type = PLAYER;
	set_image(game, game->player.tile->left);
	set_image(game, game->player.tile);
}

static void	left_move(t_game *game)
{
	ft_printf("PLAYER MOVE LEFT\nMISSING COLLECTABLES: %i\n", game->collects);
	game->player.tile->type = EMPTY;
	game->player.tile = game->player.tile->left;
	game->player.tile->type = PLAYER;
	set_image(game, game->player.tile->right);
	set_image(game, game->player.tile);
}

void	move_to(int key, t_game *game)
{
	ch_dir(key, game);
	if (key == UP)
		up_move(game);
	else if (key == DOWN)
		down_move(game);
	else if (key == RIGHT)
		right_move(game);
	else if (key == LEFT)
		left_move(game);
	ft_printf("MOVES: %i\n", game->moves++);
}
