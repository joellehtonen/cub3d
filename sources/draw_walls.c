/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/24 09:52:55 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	correct_distortion(t_game *game)
{
	game->ray.length = game->ray.length * cos(game->ray.angle - game->player.angle);
}

// 	wall_h = (TILE_SIZE / mlx->ray->distance) * ((S_W / 2) / tan(mlx->ply->fov_rd / 2)); // get the wall height
void    draw_walls(t_game *game)
{
    float	line_height;
	float	wall_height;
	float	wall_top;
	float	wall_bottom;

	line_height = TILE_SIZE * WINDOW_HEIGHT / game->ray.length;
	if (line_height > WINDOW_HEIGHT)
		line_height = WINDOW_HEIGHT;
	wall_height = 

		
	wall_top = (WINDOW_HEIGHT / 2) - 
}