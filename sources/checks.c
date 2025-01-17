/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:28:30 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/17 12:12:27 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// changed this to float, not sure if it still works as it should
bool	is_wall_float(t_game *game, float x, float y)
{
	int x_map;
	int y_map;

	x_map = floor(x / TILE_SIZE); //or just typecast to int?
	y_map = floor(y / TILE_SIZE);
	// x_map = (int)x;
	// y_map = (int)y;
	if (x_map < 0 || y_map < 0 || x_map > game->width || y_map > game->height)
	{
		printf("ERROR! - INFINITY!!! --- x_map: %d, y_map: %d   ", x_map, y_map);
		return (true);
	}
	if (game->map[y_map / TILE_SIZE][x_map / TILE_SIZE] == '1')
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
