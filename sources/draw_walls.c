/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/28 15:09:11 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	draw_background(t_game *game)
// {
// 	int	i;
// 	int j;

// 	game->background = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	// add checks
// 	i = 0;
// 	while (i < WINDOW_WIDTH)
// 	{
// 		j = 0;
// 		while (j < WINDOW_HEIGHT / 2)
// 			mlx_put_pixel(game->background, i, j++, 0x00FFFFFF);
// 		while (j < WINDOW_HEIGHT)
// 			mlx_put_pixel(game->background, i, j++, 0x0066FFFF);
// 		i++;
// 	}
// 	mlx_image_to_window(game->mlx, game->background, 0, 0);
// 	game->background->instances[0].z = -2;
// }

static void	draw_floor_ceiling(t_game *game, int ray)
{
	int	i;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		if (place_for_minimap(game, ray, i) == false)
			mlx_put_pixel(game->frame, ray, i, 0x87CEEBFF);
		i++;
	}
	while (i < WINDOW_HEIGHT)
	{
		mlx_put_pixel(game->frame, ray, i, 0xC2B280FF);
		i++;
	}
}

static void draw_walls(t_game *game, float start, float end, int ray)
{
	uint32_t color;

	//color = get_color(game);
	while (start <= end && start < WINDOW_HEIGHT)
	{
		if (place_for_minimap(game, ray, start) == false)
		{
			color = get_pixel_color(game, ray, start);
			mlx_put_pixel(game->frame, ray, start, color);
		}
		start++;
	}
}

void    render_ray_into_frame(t_game *game, int ray)
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
	draw_floor_ceiling(game, ray);
	draw_walls(game, wall_top, wall_bottom, ray);
}
