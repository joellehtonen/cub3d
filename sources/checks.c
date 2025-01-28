/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:28:30 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/27 14:16:33 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_wall_float(t_game *game, float x, float y)
{
	int x_int;
	int y_int;

	x_int = floor(x / TILE_SIZE);
	if (game->ray.direction_left == true && fabs(fmod(x, TILE_SIZE)) < 0.0001)
		x_int -= 1;
	y_int = floor(y / TILE_SIZE);
	if (game->ray.direction_up == true && fabs(fmod(y, TILE_SIZE)) < 0.0001)
		y_int -= 1;
	if (x_int < 0 || y_int < 0 || x_int > (game->width_in_tiles - 1) || y_int > (game->height_in_tiles - 1))
		return (true);
	if (game->map[y_int][x_int] == '1')
		return (true);
	else
		return (false);
}

bool	is_wall(t_game *game, int x, int y)
{
	if (game->map[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (true);
	else
		return (false);
} 
