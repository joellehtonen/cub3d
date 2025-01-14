/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/14 16:14:28 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_wall(t_game *game, int x, int y)
{
	if (game->map[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (true);
	else
		return (false);
}

static int	move_up(t_game *game)
{
	t_box	ghost_box;
	int		x;
	int		new_y;

	x = game->player.x;
	new_y = game->player.y - MOVE_SPEED;
	ghost_box = (t_box){x, new_y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x, ghost_box.y)
		&& !is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y))
	{
		game->player.player_img->instances[0].y -= MOVE_SPEED;
		game->player.y -= MOVE_SPEED;
		return (1);
	}
	else
		return (0);
}

static int	move_down(t_game *game)
{
	t_box	ghost_box;
	int		x;
	int		new_y;

	x = game->player.x;
	new_y = game->player.y + MOVE_SPEED;
	ghost_box = (t_box){x, new_y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE)
		&& !is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE))
	{
		game->player.player_img->instances[0].y += MOVE_SPEED;
		game->player.y += MOVE_SPEED;
		return (1);
	}
	else
		return (0);
}

static int	move_left(t_game *game)
{
	t_box	ghost_box;
	int		new_x;
	int		y;

	y = game->player.y;
	new_x = game->player.x - MOVE_SPEED;
	ghost_box = (t_box){new_x, y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x, ghost_box.y)
		&& !is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE))
	{
		game->player.player_img->instances[0].x -= MOVE_SPEED;
		game->player.x -= MOVE_SPEED;
		return (1);
	}
	else
		return (0);
}

static int	move_right(t_game *game)
{
	t_box	ghost_box;
	int		new_x;
	int		y;

	y = game->player.y;
	new_x = game->player.x + MOVE_SPEED;
	ghost_box = (t_box){new_x, y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y)
		&& !is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE))
	{
		game->player.player_img->instances[0].x += MOVE_SPEED;
		game->player.x += MOVE_SPEED;
		return (1);
	}
	else
		return (0);
}

static int	rotate_left(t_game *game)
{
	//something
	return (1);
}

static int	rotate_right(t_game *game)
{
	//something
	return (1);
}

void	controls(void *content)
{
	int		movement;
	t_game	*game;

	game = (t_game *)content;
	movement = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		free_all(game);
		exit (1);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		movement += move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		movement += move_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		movement += move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		movement += move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		movement += rotate_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		movement += rotate_right(game);
}
