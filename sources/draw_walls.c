/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 09:50:59 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	@brief Finds the corresponding texture depending on the ray direction
	 and which wall, horizontal or vertical, it hit.
	@param *game Our game struct
	@return The chosen texture
*/
mlx_texture_t	*choose_texture(t_game *game)
{
	mlx_texture_t	*texture;

	if (game->ray.horizontal_door_hit == true \
		|| game->ray.vertical_door_hit == true)
	{
		texture = game->door_texture;
	}
	else if (game->ray.horizontal == true)
	{
		if (game->ray.direction_up == true)
			texture = game->south_texture;
		else
			texture = game->north_texture;
	}
	else
	{
		if (game->ray.direction_left == true)
			texture = game->east_texture;
		else
			texture = game->west_texture;
	}
	return (texture);
}

/*
	@brief Finds the x-coordinate within the texture that 
	 matches the relative position of where the ray hits the wall.
	@param *game Our game struct
	@param *texture Texture to be drawn, contains the color information we need
	@return The x-coordinate
*/
int	get_x_coordinate(t_game *game, mlx_texture_t *texture)
{
	int	x;

	if (game->ray.horizontal == true)
	{
		if (game->ray.direction_up == false)
			x = (1 - fmod(game->ray.x, game->tile_size) / game->tile_size) \
				* texture->width;
		else
			x = fmod(game->ray.x, game->tile_size) / game->tile_size \
				* texture->width;
	}
	else
	{
		if (game->ray.direction_left == true)
			x = (1 - fmod(game->ray.y, game->tile_size) / game->tile_size) \
				* texture->width;
		else
			x = fmod(game->ray.y, game->tile_size) / game->tile_size \
				* texture->width;
	}
	return (x);
}

/*
	@brief Draws the textures as walls to the window.
	@param *game Our game struct
	@param start Location of the uppermost pixel of the wall to be drawn
	@param end Location of the last pixel of the wall to be drawn
	@param ray Number of the ray, essentially the x-coordinate
*/
void	draw_walls(t_game *game, int start, int end, int ray)
{
	mlx_texture_t	*texture;
	uint32_t		color;
	int				texture_x;
	float			texture_y;
	float			step;

	texture = choose_texture(game);
	step = texture->height / game->ray.wall_height;
	texture_y = (start - (WINDOW_HEIGHT / 2) + \
		(game->ray.wall_height / 2)) * step;
	texture_x = get_x_coordinate(game, texture);
	while (start <= end && start < WINDOW_HEIGHT)
	{
		if (DARK == 0)
			extract_color_data(texture, &color, \
				((texture->width * (int)texture_y + texture_x) * 4));
		else
			extract_color_data_bw(texture, &color, \
				((texture->width * (int)texture_y + texture_x) * 4));
		mlx_put_pixel(game->frame, ray, start, color);
		start++;
		texture_y += step;
		if (texture_y >= texture->height)
			texture_y -= texture->height;
	}
}

/*
	@brief Draws floors (lower 50% of the image) and ceilings (upper 50%)
	 according to the values in the map file.
	@param *game Our game struct
	@param ray Number of the ray, essentially the x-coordinate
*/
static void	draw_floor_ceiling(t_game *game, int ray)
{
	int	i;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		mlx_put_pixel(game->frame, ray, i, game->ceiling_rgb);
		i++;
	}
	while (i < WINDOW_HEIGHT)
	{
		mlx_put_pixel(game->frame, ray, i, game->floor_rgb);
		i++;
	}
}

/*
	@brief Calculates the dimensions of the wall,
	 then renders each one pixel wide ray into a pixel wide image onto window.
	@param *game Our game struct
	@param ray Number of the ray, essentially the x-coordinate
*/
void	render_ray_into_frame(t_game *game, int ray)
{
	float	wall_top;
	float	wall_bottom;

	correct_distortion(game);
	game->ray.wall_height = game->tile_size * WINDOW_HEIGHT / game->ray.length;
	wall_top = (WINDOW_HEIGHT / 2) - (game->ray.wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (WINDOW_HEIGHT / 2) + (game->ray.wall_height / 2);
	if (wall_bottom > WINDOW_HEIGHT)
		wall_bottom = WINDOW_HEIGHT;
	draw_floor_ceiling(game, ray);
	draw_walls(game, (int)wall_top, (int)wall_bottom, ray);
}
