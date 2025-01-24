/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/24 12:47:36 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// static void	correct_distortion(t_game *game)
// {
// 	game->ray.length = game->ray.length * cos(game->ray.angle - game->player.angle);
// }

static void	draw_floor_ceiling(t_game *game, int x)
{
	int	i;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
		mlx_put_pixel(game->frame, x, i++, game->found_ceiling_rgb);
	while (i < WINDOW_HEIGHT)
		mlx_put_pixel(game->frame, x, i++, game->found_floor_rgb);
}

static void draw_wall(t_game *game, float top, float bottom, int x)
{
	int color;

	color = 0x0000FF; //later determine based direction, even later replace by textures
	while (top > bottom)
	{
		mlx_put_pixel(game->frame, x, top, color);
		top--;
	}
}

void    render_frame(t_game *game)
{
	float		wall_height;
	float		wall_top;
	float		wall_bottom;
	int			x;

	wall_height = TILE_SIZE * WINDOW_HEIGHT / game->ray.length;
	wall_top = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (WINDOW_HEIGHT / 2) + (wall_height / 2);
	if (wall_bottom > WINDOW_HEIGHT)
		wall_bottom = WINDOW_HEIGHT;
	if (game->frame != NULL)
		mlx_delete_image(game->mlx, game->frame);
	mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		draw_wall(game, wall_top, wall_bottom, x);
		draw_floor_ceiling(game, x);
		x++;
	}
	mlx_image_to_window(game->mlx, game->frame, 0, 0);
}
