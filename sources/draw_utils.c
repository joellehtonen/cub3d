/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:59:10 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/28 12:18:01 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	place_for_minimap(t_game* game, int x, int y)
{
	if (x < (game->width_in_tiles * TILE_SIZE) && y < (game->height_in_tiles * TILE_SIZE))
		return (true);
	else
		return (false);
}

void	correct_distortion(t_game *game)
{
	game->ray.length = game->ray.length * cos(game->ray.angle - game->player.angle);
}

int	get_color(t_game *game)
{
	if (game->ray.horizontal == true)
	{
		if (game->ray.direction_up == true)
			return (0xCD5C5CFF);
		else
			return (0x8B0000FF);
	}
	else
	{
		if (game->ray.direction_left == true)
			return (0xFF8C00FF);
		else
			return (0xB22222FF);
	}
}
// texture_buffer[n][y * 64 + x]. 
// This skips y rows by multiplying the width of the texture, 
// and then adds x to get the pixel.

int	get_pixel_color(t_game *game, int x, int y)
{
	int color;
	
	if (game->ray.horizontal == true)
	{
		if (game->ray.direction_up == true) //south texture
			color = get_texture_color(game, game->south_texture, x, y);
		else //north texture
			color = get_texture_color(game, game->north_texture, x, y);
	}
	else
	{
		if (game->ray.direction_left == true) //east texture
			color = get_texture_color(game, game->east_texture, x, y);
		else //west texture
			color = get_texture_color(game, game->west_texture, x, y);
	}
	
}
// https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/
// texture_buffer[n][y * 64 + x]. 
// This skips y rows by multiplying the width of the texture, 
// and then adds x to get the pixel.

int 	get_texture_color(t_game *game, mlx_texture_t *texture, int x, int y)
{
	
}
