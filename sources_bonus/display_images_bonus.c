/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:45:15 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:05 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	images_to_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->minimap.wall_img, x * game->tile_size, y * game->tile_size) < 0)
			return (0);
	}
	if (game->map[y][x] == '0')
	{
		if (mlx_image_to_window(game->mlx, game->minimap.floor_img, x * game->tile_size, y * game->tile_size) < 0)
			return (0);
	}
	if (game->map[y][x] == 'N' || game->map[y][x] == 'S' ||
		game->map[y][x] == 'W' || game->map[y][x] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->minimap.floor_img, x * game->tile_size, y * game->tile_size) < 0)
			return (0);
		game->player.x = x * game->tile_size + game->tile_size / 2;
		game->player.y = y * game->tile_size + game->tile_size / 2;
	}
	if (game->map[y][x] == '.' || game->map[y][x] == ' ')
	{
		if (mlx_image_to_window(game->mlx, game->minimap.empty_map_img, x * game->tile_size, y * game->tile_size) < 0)
			return (0);
	}
	
	return (1);
}

static void flame_images_to_window(t_game *game)
{
	int i;

	i = 0;
	while (i < 12)
	{
		if (mlx_image_to_window(game->mlx, game->animation.flame_img[i], FLAME_X, FLAME_Y) < 0)
			error_exit_and_free(game, "MLX could not display image in window");
		i++;
	}
}

void	display_images(t_game *game)
{
	int	x;
	int	y;

	mlx_image_to_window(game->mlx, game->frame, 0, 0);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!(images_to_window(game, x, y)))
				error_exit_and_free(game, "MLX could not display image in window");
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(game->mlx, game->minimap.player_img, game->player.x, game->player.y) < 0)
		error_exit_and_free(game, "MLX could not display image in window");
	if (mlx_image_to_window(game->mlx, game->minimap.minimap_img, 0, 0) < 0)
		error_exit_and_free(game, "MLX could not display image in window");
	if (mlx_image_to_window(game->mlx, game->animation.zippo_img, ZIPPO_X, ZIPPO_Y) < 0) 
		error_exit_and_free(game, "MLX could not display image in window");
	flame_images_to_window(game);
}
