/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:22:12 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/28 15:58:58 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static uint32_t	extract_color_data(mlx_texture_t *texture, int location)
{
	uint8_t 	red;
	uint8_t 	green;
	uint8_t 	blue;
	uint8_t 	alpha;
	uint32_t 	rgba;

	blue = texture->pixels[location];
	green = texture->pixels[location + 1];
	red = texture->pixels[location + 2];
	alpha = texture->pixels[location + 3];
	rgba = (red << 24) | (green << 16) | (blue << 8) | (alpha);
	//printf("pixel at 0,0 - r: %d, g: %d, b: %d, alpha: %d\n", red, green, blue, alpha);
	return (rgba);
}

int	get_y_coord(t_game *game, mlx_texture_t *texture)
{
	int offset;

	offset = texture->height / 
}

static uint32_t	find_texture_color(t_game *game, mlx_texture_t *texture, int x, int y)
{
	uint32_t	color;
	int			pixel_location;
	int			x_coord;
	int			y_coord;
	
	//x = 0;
	//y = 0;
	// if (x < 0 || y < 0)
	// 	return (0xFFFFFFFF);
	// if ((uint32_t)x >= texture->width || (uint32_t)y >= texture->height)
	// 	return (0x000000FF);
	// if (game->ray.horizontal == true)
	// 	x_coord = fmod(game->ray.x * (texture->width / TILE_SIZE), texture->width);
	// else
	// 	x_coord = fmod(game->ray.y * (texture->width / TILE_SIZE), texture->width);
	x_coord = (int)(game->ray.x * texture->width);
	y_coord = get_y_coord(game, texture);
	
	pixel_location = (texture->width * y_coord + x_coord) * 4;
	color = extract_color_data(texture, pixel_location);
	return (color);
}

uint32_t	get_pixel_color(t_game *game, int x, int y)
{
	int color;
	
	if (game->ray.horizontal == true)
	{
		if (game->ray.direction_up == true) //south texture
			color = find_texture_color(game, game->south_texture, x, y);
		else //north texture
			color = find_texture_color(game, game->north_texture, x, y);
	}
	else
	{
		if (game->ray.direction_left == true) //east texture
			color = find_texture_color(game, game->east_texture, x, y);
		else //west texture
			color = find_texture_color(game, game->west_texture, x, y);
	}
	return (color);
}
