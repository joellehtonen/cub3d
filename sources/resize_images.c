/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:42:02 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/31 09:38:46 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void resize_torch_images(t_game *game)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (!mlx_resize_image((game->flame_img)[i], FLAME_SIZE, FLAME_SIZE))
			error_exit_and_free(game, "MLX failed to resize an image");
		i++;
	}
}

void	resize_images(t_game *game)
{
	if (!mlx_resize_image(game->minimap_wall_img, TILE_SIZE, TILE_SIZE))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->minimap_floor_img, TILE_SIZE, TILE_SIZE))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->empty_map_img, TILE_SIZE, TILE_SIZE))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->player.minimap_player_img, TILE_SIZE / 4,
			TILE_SIZE / 4))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->zippo_img, ZIPPO_SIZE, ZIPPO_SIZE))
		error_exit_and_free(game, "MLX failed to resize an image");
	resize_torch_images(game);
}
