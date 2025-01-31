/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:45:15 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/31 09:18:11 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	images_to_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->minimap_wall_img, x * TILE_SIZE, y * TILE_SIZE) < 0)
			return (0);
	}
	if (game->map[y][x] == '0')
	{
		if (mlx_image_to_window(game->mlx, game->minimap_floor_img, x * TILE_SIZE, y * TILE_SIZE) < 0)
			return (0);
	}
	if (game->map[y][x] == 'N' || game->map[y][x] == 'S' ||
		game->map[y][x] == 'W' || game->map[y][x] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->minimap_floor_img, x * TILE_SIZE, y * TILE_SIZE) < 0)
			return (0);
		game->player.x = x * TILE_SIZE + TILE_SIZE / 2;
		game->player.y = y * TILE_SIZE + TILE_SIZE / 2;
	}
	
	return (1);
}

static void flame_images_to_window(t_game *game)
{
	int i;

	i = 0;
	while (i < 12)
	{
		if (mlx_image_to_window(game->mlx, game->flame_img[i], FLAME_X, FLAME_Y) < 0)
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
	if (mlx_image_to_window(game->mlx, game->player.minimap_player_img, game->player.x, game->player.y) < 0)
		error_exit_and_free(game, "MLX could not display image in window");
	if (mlx_image_to_window(game->mlx, game->minimap_img, 0, 0) < 0)
		error_exit_and_free(game, "MLX could not display image in window");
	if (mlx_image_to_window(game->mlx, game->zippo_img, ZIPPO_X, ZIPPO_Y) < 0) 
		error_exit_and_free(game, "MLX could not display image in window");
	flame_images_to_window(game);
	if (mlx_image_to_window(game->mlx, game->flame_mem_img, FLAME_X, FLAME_Y) < 0) //REMOVE MAYBE
		error_exit_and_free(game, "MLX could not display image in window");
}
