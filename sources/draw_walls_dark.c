/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/29 20:58:30 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_floor_ceiling_dark(t_game *game, int ray)
{
	int			i;
	uint32_t	color;
	int			counter;

	i = 0;
	color = 0x00000000;
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
		if (top >= WINDOW_HEIGHT)
			break ;
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
