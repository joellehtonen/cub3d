/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/29 21:17:32 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// static mlx_texture_t *choose_texture(t_game *game)
// {
// 	mlx_texture_t *texture;
	
// 	if (game->ray.horizontal == true)
// 	{
// 		if (game->ray.direction_up == true) //south texture
// 			texture = game->south_texture;
// 		else //north texture
// 			texture = game->north_texture;
// 	}
// 	else
// 	{
// 		if (game->ray.direction_left == true) //east texture
// 			texture = game->east_texture;
// 		else //west texture
// 			texture = game->west_texture;
// 	}
// 	return (texture);
// }

// static int	get_x_coordinate(t_game *game, mlx_texture_t *texture)
// {
// 	int	x;
	
// 	if (game->ray.horizontal == true)
// 	{
// 		if (game->ray.direction_up == false)
// 			x = (1 - fmod(game->ray.x, TILE_SIZE) / TILE_SIZE) * texture->width;
// 		else
// 			x = fmod(game->ray.x, TILE_SIZE) / TILE_SIZE * texture->width;
// 	}
// 	else
// 	{
// 		if (game->ray.direction_left == true)
// 			x = (1 - fmod(game->ray.y, TILE_SIZE) / TILE_SIZE) * texture->width;
// 		else
// 			x = fmod(game->ray.y, TILE_SIZE) / TILE_SIZE * texture->width;
// 	}
// 	return (x);
// }

// static void draw_walls(t_game *game, int start, int end, int ray)
// {
// 	mlx_texture_t	*texture;
// 	uint32_t 		color;
// 	int				texture_x;
// 	float			texture_y;
// 	float			step;
	
// 	//color = get_color(game);
// 	texture = choose_texture(game);
// 	step = texture->height / game->ray.wall_height;
// 	texture_y = (start - (WINDOW_HEIGHT / 2) + (game->ray.wall_height / 2)) * step;
// 	texture_x = get_x_coordinate(game, texture);
// 	while (start <= end && start < WINDOW_HEIGHT)
// 	{
// 		// if (place_for_minimap(game, ray, start) == false)
// 		color = extract_color_data(texture, ((texture->width * (int)texture_y + texture_x) * 4));
// 		mlx_put_pixel(game->frame, ray, start, color);
// 		start++;
// 		//texture_y = (int)texture_y % texture->height;
// 		texture_y += step;
// 		if (texture_y >= texture->height)
// 			texture_y -= texture->height;
// 	}
// }

static void	draw_floor_ceiling_dark(t_game *game, int ray)
{
	int			i;
	uint32_t	color;
	int			counter;

	i = 0;
	//color = 0x50400000;
	color = 0x0000000;
	counter = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		mlx_put_pixel(game->frame, ray, i, 0x000000FF); //ceiling
		i++;
	}
	i = WINDOW_HEIGHT;
	while (i > WINDOW_HEIGHT / 2)
	{
		mlx_put_pixel(game->frame, ray, i--, color);
		counter++;
		if (counter % 3 != 0)
			color++;
		if (color >= 255)
			color = 255;
	}
}

static void draw_walls(t_game *game, float top, float bottom, int ray)
{
	int color;

	color = get_color(game);
	while (top <= bottom && top < WINDOW_HEIGHT)
	{
		if (place_for_minimap(game, ray, top) == false)
			mlx_put_pixel(game->frame, ray, top, color);
		top++;
	}
}

static void draw_black(t_game *game, float top, float bottom, int ray)
{
	int color;

	color = 0x000000FF;
	while (top <= bottom)
	{
		if (place_for_minimap(game, ray, top) == false)
			mlx_put_pixel(game->frame, ray, top, color);
		top++;
	}
}

void    render_ray_into_frame_dark(t_game *game, int ray)
{
	float		wall_height;
	float		wall_top;
	float		wall_bottom;

	correct_distortion(game);
	wall_height = TILE_SIZE * WINDOW_HEIGHT / game->ray.length;
	wall_top = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (WINDOW_HEIGHT / 2) + (wall_height / 2);
	if (wall_bottom > WINDOW_HEIGHT)
		wall_bottom = WINDOW_HEIGHT;
	draw_floor_ceiling_dark(game, ray);
	if (game->ray.length < 60)
		draw_walls(game, wall_top, wall_bottom, ray);
	else
		draw_black(game, wall_top, wall_bottom, ray);
}
