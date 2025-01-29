/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:22:12 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/29 14:27:05 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

uint32_t	extract_color_data(mlx_texture_t *texture, int location)
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

uint32_t	find_pixel_color(t_game *game, mlx_texture_t *texture, int start)
{
	uint32_t	color;
	int			pixel_location;
	int			texture_x;
	int			texture_y;
	
	// maybe calculate these in is_wall_float or choose_shorter_distance
	if (game->ray.horizontal == true)
		texture_x = fmod(game->ray.x, TILE_SIZE) / TILE_SIZE * texture->width;
	else
		texture_x = fmod(game->ray.y, TILE_SIZE) / TILE_SIZE * texture->width;
	texture_y = (start - (WINDOW_HEIGHT / 2) + (game->ray.wall_height / 2)) * (texture->height / game->ray.wall_height);
	if ((uint32_t)texture_x >= texture->width || (uint32_t)texture_y >= texture->height)
		return (0x000000FF);
	pixel_location = (texture->width * texture_y + texture_x) * 4;
	color = extract_color_data(texture, pixel_location);
	return (color);
}
