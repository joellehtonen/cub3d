/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/28 17:06:09 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_floor_ceiling_dark(t_game *game, int ray)
{
	int		i;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		if (place_for_minimap(game, ray, i) == false)
			mlx_put_pixel(game->frame, ray, i, 0x000000FF); //ceiling
		i++;
	}
	while (i < WINDOW_HEIGHT / 1.3)
		mlx_put_pixel(game->frame, ray, i++, 0x000000FF); //distant floor
	while (i < WINDOW_HEIGHT)
		mlx_put_pixel(game->frame, ray, i++, 0x00000000); //closer floor
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
