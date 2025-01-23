/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:28:30 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/23 11:53:20 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_wall_float(t_game *game, float x, float y)
{
	int x_int;
	int y_int;

	x_int = floor(x / TILE_SIZE);
	if (game->ray.direction_left == true && fmod(x, TILE_SIZE) == 0)
		x_int -= 1;
	y_int = floor(y / TILE_SIZE);
	if (game->ray.direction_up == true && fmod(y, TILE_SIZE) == 0)
		y_int -= 1;
	//printf("WALL_CHECK: X_INT is %d, Y_INT is %d\n", x_int, y_int);
	if (x_int < 0 || y_int < 0 || x_int > (WINDOW_WIDTH / TILE_SIZE) - 1 || y_int > (WINDOW_HEIGHT / TILE_SIZE) - 1)
	{
		//printf("ERROR! - INFINITY!!! --- x_int: %d, y_int: %d\n", x_int, y_int);
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
