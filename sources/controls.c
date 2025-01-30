/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/30 09:49:28 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	rotate_player(t_game *game, double direction)
{
	if (direction == RIGHT)
	{
		game->player.angle += ROTATE_SPEED;
		game->ray.angle += ROTATE_SPEED;
	}
	else if (direction == LEFT)
	{
		game->player.angle -= ROTATE_SPEED;
		game->ray.angle -= ROTATE_SPEED;
	}
	reset_angles(game);
	determine_ray_direction(game);
	return (true);
}

static bool	move_player(t_game *game, double direction)
{
	double	new_x;
	double	new_y;
	
	new_x = game->player.x + cos(game->player.angle + direction) * MOVE_SPEED;
	new_y = game->player.y + sin(game->player.angle + direction) * MOVE_SPEED;
	if (is_wall(game, new_x, new_y) == false)
	{
		game->player.x = new_x;
		game->player.y = new_y;
		game->player.player_img->instances[0].x = new_x;
		game->player.player_img->instances[0].y = new_y;
		
		return (true);
	}
	else
		return (false);
}

bool controls(t_game *game)
{
	bool	movement;
	
	movement = false;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		free_all(game);
		exit (EXIT_SUCCESS);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		movement = move_player(game, FORWARD);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		movement = move_player(game, BACK);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		movement = move_player(game, LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		movement = move_player(game, RIGHT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		movement = rotate_player(game, LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		movement = rotate_player(game, RIGHT);
	return (movement);
}
