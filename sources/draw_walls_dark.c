/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/03 10:04:51 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_walls(t_game *game, int start, int end, int ray)
{
	mlx_texture_t	*texture;
	uint32_t		color;
	int				texture_x;
	float			texture_y;
	float			step;

	texture = choose_texture(game);
	step = texture->height / game->ray.wall_height;
	texture_y = (start - (WINDOW_HEIGHT / 2) \
		+ (game->ray.wall_height / 2)) * step;
	texture_x = get_x_coordinate(game, texture);
	while (start <= end && start < WINDOW_HEIGHT)
	{
		extract_color_data_dark(texture, &color, \
			((texture->width * (int)texture_y + texture_x) * 4));
		mlx_put_pixel(game->frame, ray, start, color);
		start++;
		texture_y += step;
		if (texture_y >= texture->height)
			texture_y -= texture->height;
	}
}

static void	draw_floor_ceiling_dark(t_game *game, int ray)
{
	int			i;
	uint32_t	color;
	int			counter;

	i = WINDOW_HEIGHT - 1;
	color = 0x0000000;
	counter = 0;
	while (i > WINDOW_HEIGHT / 2)
	{
		mlx_put_pixel(game->frame, ray, i, color);
		i--;
		counter++;
		if (counter % 3 != 0)
			color++;
		if (color >= 255)
			color = 255;
	}
	while (i > 0)
	{
		mlx_put_pixel(game->frame, ray, i--, 0x000000FF);
	}
}

static void	draw_gradient(t_game *game, float top, float bottom, int ray)
{
	int		color;
	int		minimum_ray;
	float	step;

	minimum_ray = 60;
	step = (game->ray.length - minimum_ray) / 10;
	color = 0x000000FF * step;
	// if (game->ray.length > 69)
	// 	color = 0x000000EE;
	// else if (game->ray.length > 68)
	// 	color = 0x000000DD;
	// else if (game->ray.length > 67)
	// 	color = 0x000000CC;
	// else if (game->ray.length > 66)
	// 	color = 0x000000BB;
	// else if (game->ray.length > 65)
	// 	color = 0x000000AA;
	// else if (game->ray.length > 64)
	// 	color = 0x00000088;
	// else if (game->ray.length > 63)
	// 	color = 0x00000066;
	// else if (game->ray.length > 62)
	// 	color = 0x00000044;
	// else if (game->ray.length > 61)
	// 	color = 0x00000022;
	while (top <= bottom)
		mlx_put_pixel(game->frame, ray, top++, color);
}

static void	draw_black(t_game *game, float top, float bottom, int ray)
{
	int	color;

	color = 0x000000FF;
	while (top <= bottom)
	{
		mlx_put_pixel(game->frame, ray, top, color);
		top++;
	}
}

void	render_ray_into_frame_dark(t_game *game, int ray)
{
	float		wall_top;
	float		wall_bottom;

	correct_distortion(game);
	game->ray.wall_height = game->tile_size * WINDOW_HEIGHT / game->ray.length;
	wall_top = (WINDOW_HEIGHT / 2) - (game->ray.wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (WINDOW_HEIGHT / 2) + (game->ray.wall_height / 2);
	if (wall_bottom > WINDOW_HEIGHT)
		wall_bottom = WINDOW_HEIGHT;
	draw_floor_ceiling_dark(game, ray);
	if (game->ray.length < 60)
		draw_walls(game, wall_top, wall_bottom, ray);
	else if (game->ray.length > 60 && game->ray.length < 70)
		draw_gradient(game, wall_top, wall_bottom, ray);
	else
		draw_black(game, wall_top, wall_bottom, ray);
}
