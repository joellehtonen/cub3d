/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 14:12:37 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_floor_ceiling_dark(t_game *game, int ray)
{
	int			i;
	uint32_t	color;
	int			counter;

	i = WINDOW_HEIGHT - 1;
	color = 0x0000000;
	counter = 0;
	while (i > WINDOW_HEIGHT / 2 \
		+ (FLAME_SIZE - game->animation.new_flame_size_x))
	{
		mlx_put_pixel(game->frame, ray, i, color);
		i--;
		counter++;
		if (counter % 12 != 0)
		{
			color++;
		}
		if (color >= 255)
			color = 255;
	}
	while (i > 0)
	{
		mlx_put_pixel(game->frame, ray, i--, 0x000000FF);
	}
}

static void	draw_black(t_game *game, float top, float bottom, int ray)
{
	int	color;

	color = 0x000000FF;
	while (top < bottom)
	{
		mlx_put_pixel(game->frame, ray, top, color);
		top++;
	}
}

void	render_ray_into_frame_dark(t_game *game, int ray)
{
	float		wall_top;
	float		wall_bottom;
	double		min_ray;

	min_ray = game->animation.new_flame_size_x / 10;
	correct_distortion(game);
	game->ray.wall_height = game->tile_size * WINDOW_HEIGHT / game->ray.length;
	wall_top = (WINDOW_HEIGHT / 2) - (game->ray.wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (WINDOW_HEIGHT / 2) + (game->ray.wall_height / 2);
	if (wall_bottom > WINDOW_HEIGHT)
		wall_bottom = WINDOW_HEIGHT;
	draw_floor_ceiling_dark(game, ray);
	if (game->ray.length < min_ray)
		draw_walls(game, wall_top, wall_bottom, ray);
	else
		draw_black(game, wall_top, wall_bottom, ray);
}
