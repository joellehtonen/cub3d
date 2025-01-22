/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:28:30 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/22 10:38:49 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_wall_float(t_game *game, float x, float y)
{
	int x_int;
	int y_int;

	x_int = floor(x / TILE_SIZE);
	y_int = floor(y / TILE_SIZE);
	printf("WALL_CHECK: X_INT is %d, Y_INT is %d\n", x_int, y_int);
	if (x_int < 0 || y_int < 0 || x_int > WINDOW_WIDTH || y_int > WINDOW_HEIGHT)
	{
		//printf("ERROR! - INFINITY!!! --- x_int: %d, y_int: %d   ", x_int, y_int);
		return (true);
	}
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
