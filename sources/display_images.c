/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:45:15 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/28 16:53:52 by eberkowi         ###   ########.fr       */
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
		game->player.x = x * TILE_SIZE;
		game->player.y = y * TILE_SIZE;
	}
	
	return (1);
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
	if (mlx_image_to_window(game->mlx, game->player.player_img, game->player.x, game->player.y) < 0)
		return ; //add fail check here
	if (mlx_image_to_window(game->mlx, game->minimap_img, 0, 0) < 0)
		return ; //add fail check here
}
