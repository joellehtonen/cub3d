/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/18 18:12:15 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	rotate_player(t_game *game, double direction)
{
	if (direction == LEFT)
	{
		game->player.angle_radian -= ROTATE_SPEED;
		if (game->player.angle_radian < 0)
			game->player.angle_radian += (2 * PI);
	}
	else if (direction == RIGHT)
	{
		game->player.angle_radian += ROTATE_SPEED;
		if (game->player.angle_radian >= (2 * PI))
			game->player.angle_radian -= (2 * PI);
	}	
	game->player.dx = cos(game->player.angle_radian);
	game->player.dy = sin(game->player.angle_radian);
	game->ray.angle = game->player.angle_radian - (FOV / 2);
	if (game->ray.angle < 0)
		game->ray.angle += (2 * PI);
	if (game->ray.angle >= (2 * PI))
		game->ray.angle -= (2 * PI);
	determine_ray_direction(game);
	return (true);
}

static bool	move_player(t_game *game, double direction)
{
	double	new_x;
	double	new_y;
	
	new_x = game->player.x + cos(game->player.angle_radian + direction) * MOVE_SPEED;
	new_y = game->player.y + sin(game->player.angle_radian + direction) * MOVE_SPEED;
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
