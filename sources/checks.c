/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:28:30 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/17 17:20:43 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_wall_float(t_game *game, float x, float y)
{
	int x_int;
	int y_int;

	x_int = (int)x;
	y_int = (int)y;
	if (x_int < 0 || y_int < 0 || x_int > game->width || y_int > game->height)
	{
		//printf("ERROR! - INFINITY!!! --- x_int: %d, y_int: %d   ", x_int, y_int);
		return (true);
	}
	if (game->map[y_int / TILE_SIZE][x_int / TILE_SIZE] == '1')
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
