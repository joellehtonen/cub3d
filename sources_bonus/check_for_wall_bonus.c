/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_wall_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:28:30 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:00 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

/*
	@brief Checks whether there is a closed door 
	 in the map in the given coordinates. 
	@param *game Our game struct
	@param x X-coordinate to check
	@param y Y-coordinate to check
	@return boolean on whether there is a door or not
*/
static bool	is_door(t_game *game, int x, int y, bool horizontal)
{
	if (game->map[y][x] == 'D' \
		&& game->doors_closed == true)
	{
		if (horizontal == true)
			game->ray.horizontal_door_hit = true;
		else
			game->ray.vertical_door_hit = true;
		return (true);
	}
	else
		return (false);
}

/*
	@brief Checks whether there is a wall or closed door 
	 in the map in the given coordinates. This one is designed for the ray, 
	 taking into account which side of the tile the ray hits. 
	@param *game Our game struct
	@param x X-coordinate to check
	@param y Y-coordinate to check
	@return boolean on whether there is a wall or not
*/
bool	is_wall_ray(t_game *game, float x, float y, bool horizontal)
{
	int	int_x;
	int	int_y;

	int_x = floor(x / game->tile_size);
	if (game->ray.direction_left == true \
		&& fabs(fmod(x, game->tile_size)) < 0.0001)
		int_x -= 1;
	int_y = floor(y / game->tile_size);
	if (game->ray.direction_up == true \
		&& fabs(fmod(y, game->tile_size)) < 0.0001)
		int_y -= 1;
	if (int_x < 0 || int_y < 0 \
		|| int_x > (game->width_in_tiles - 1) \
		|| int_y > (game->height_in_tiles - 1))
		return (true);
	if (game->map[int_y][int_x] == '1')
		return (true);
	else if (is_door(game, int_x, int_y, horizontal) == true)
		return (true);
	else
		return (false);
}

/*
	@brief Checks whether there is a wall or a closed door 
	 in the map in the given coordinates.
	@param *game Our game struct
	@param x X-coordinate to check
	@param y Y-coordinate to check
	@return boolean on whether there is a wall or not
*/
bool	is_wall(t_game *game, int x, int y)
{
	if (game->map[y / game->tile_size][x / game->tile_size] == '1' \
		|| (game->map[y / game->tile_size][x / game->tile_size] == 'D' \
		&& game->doors_closed == true))
		return (true);
	else
		return (false);
}
