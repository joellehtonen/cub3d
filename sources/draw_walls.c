/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:57:18 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/27 11:19:13 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	correct_distortion(t_game *game)
{
	game->ray.length = game->ray.length * cos(game->ray.angle - game->player.angle);
}

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
		mlx_put_pixel(game->frame, ray, i++, 0x87CEEBFF);
	while (i < WINDOW_HEIGHT)
		mlx_put_pixel(game->frame, ray, i++, 0xC2B280FF);
}

static int	get_color(t_game *game)
{
	if (game->ray.horizontal == true)
	{
		// if (game->ray.direction_up == true)
		// 	return (0x0000AAAA);
		// else
			return (0x8B0000FF);
	}
	else
	{
		// if (game->ray.direction_up == true)
		// 	return (0x00CCCCCC);
		// else
			return (0xB22222FF);
	}
}

static void draw_walls(t_game *game, float top, float bottom, int ray)
{
	int color;

	color = get_color(game);
	while (top <= bottom)
	{
		mlx_put_pixel(game->frame, ray, top, color);
		top++;
		if (top >= WINDOW_HEIGHT)
			break ;
	}
}

// void	clear_frame(t_game *game)
// {
// 	int			i;
// 	int			alpha;
	
// 	alpha = 0x00000000;
// 	i = 0;
// 	while (i < (WINDOW_HEIGHT * WINDOW_HEIGHT))
// 	{
// 		((uint32_t *)game->frame->pixels)[i] = alpha;
// 		i++;
// 	}
// }

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
	draw_walls(game, wall_top, wall_bottom, ray); // here or somewhere else?
}
