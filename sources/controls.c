/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 09:42:38 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	@brief Rotates the player based on the direction provided. 
	 Updates lighter animation if movement occurs. 
	@param *game Our game struct
*/
void	rotate_player(t_game *game, double direction)
{
	if (direction == LEFT)
	{
		game->player.angle -= ROTATE_SPEED;
		game->ray.angle -= ROTATE_SPEED;
	}
	else if (direction == RIGHT)
	{
		game->player.angle += ROTATE_SPEED;
		game->ray.angle += ROTATE_SPEED;
	}
	else
		zippo_animation_recenter(game);
	zippo_animation_rotate(game, direction);
}

/*
	@brief Checks which key was pressed, and based on it
	 calls for the appropriate rotate function.
	@param *game Our game struct
	@return boolean on whether the player has moved
*/
static bool	player_rotation(t_game *game)
{
	double	direction;

	direction = 0.0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		direction = LEFT;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		direction = RIGHT;
	rotate_player(game, direction);
	reset_angles(game);
	determine_ray_direction(game);
	return (true);
}

/*
	@brief Checks if there is a wall in the direction
	 where player is moving. If not, moves player. 
	@param *game Our game struct
	@param direction Where player is going, expressed in radians
	@return boolean on whether the player has moved
*/
static bool	move_player(t_game *game, double direction)
{
	float	new_x;
	float	new_y;
	t_box	box;

	new_x = game->player.x + cos(game->player.angle + direction) * MOVE_SPEED;
	new_y = game->player.y + sin(game->player.angle + direction) * MOVE_SPEED;
	box = (t_box){new_x - MOVE_SIZE, new_y - MOVE_SIZE, \
		new_x + MOVE_SIZE, new_y - MOVE_SIZE, \
		new_x - MOVE_SIZE, new_y + MOVE_SIZE, \
		new_x + MOVE_SIZE, new_y + MOVE_SIZE};
	if (is_wall(game, box.top_left_x, box.top_left_y) == false \
		&& is_wall(game, box.top_right_x, box.top_right_y) == false \
		&& is_wall(game, box.bottom_left_x, box.bottom_left_y) == false \
		&& is_wall(game, box.bottom_right_x, box.bottom_right_y) == false)
	{
		game->player.x = new_x;
		game->player.y = new_y;
		game->minimap.player_img->instances[0].x = new_x;
		game->minimap.player_img->instances[0].y = new_y;
		return (true);
	}
	else
		return (false);
}

/*
	@brief Checks for keypresses and calls the actual
	 movement function with the right direction based on it. 
	 Updates lighter animation if movement occurs. 
	@param *game Our game struct
	@return boolean on whether the player has moved
*/
static bool	player_movement(t_game *game)
{
	bool	movement;

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		movement = move_player(game, FORWARD);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		movement = move_player(game, BACK);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		movement = move_player(game, LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		movement = move_player(game, RIGHT);
	if (movement == true)
		zippo_up_and_down(game);
	return (movement);
}

/*
	@brief Moves player based on keypresses and mouse, 
		and updates movement boolean. 
	@param *game Our game struct
	@return boolean on whether the player has moved
*/
bool	controls(t_game *game)
{
	bool	movement;

	movement = false;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		free_all(game);
		exit (EXIT_SUCCESS);
	}
	check_mouse_movement(game);
	movement = player_movement(game);
	movement = player_rotation(game);
	return (movement);
}
