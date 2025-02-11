/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:42:02 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/11 12:57:08 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	resize_torch_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!mlx_resize_image((game->animation.flame_img)[i],
			FLAME_SIZE, FLAME_SIZE))
			error_exit_and_free(game, "MLX failed to resize an image");
		i++;
	}
	game->animation.new_flame_size_x = FLAME_SIZE;
	game->animation.new_flame_size_y = FLAME_SIZE;
}

void	resize_images(t_game *game)
{
	if (!mlx_resize_image(game->minimap.wall_img,
			game->tile_size, game->tile_size))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->minimap.floor_img,
			game->tile_size, game->tile_size))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->minimap.empty_map_img,
			game->tile_size, game->tile_size))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->minimap.player_img,
			game->tile_size / 4,
			game->tile_size / 4))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->minimap.closed_door_img,
			game->tile_size, game->tile_size))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->minimap.open_door_img,
			game->tile_size, game->tile_size))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->animation.zippo_img, ZIPPO_SIZE, ZIPPO_SIZE))
		error_exit_and_free(game, "MLX failed to resize an image");
	resize_torch_images(game);
}
