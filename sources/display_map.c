/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:45:15 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/14 14:51:17 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	images_to_window(t_game *game, int x, int y)
{
	int	sz;

	sz = game->image_size;
	if (game->map[y][x] == '1')
		if (mlx_image_to_window(game->mlx, game->wall_img, x * sz, y * sz) < 0)
			return (0);
	if (game->map[y][x] == '0')
		if (mlx_image_to_window(game->mlx, game->floor_img, x * sz, y * sz) < 0)
			return (0);
	if (game->map[y][x] == 'N')
	{
		if (mlx_image_to_window(game->mlx, game->floor_img, x * sz, y * sz) < 0)
			return (0);
		game->player.x = x * sz;
		game->player.y = y * sz;
	}
	return (1);
}

void	display_map(t_game *game)
{
	int	x;
	int	y;

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
}
