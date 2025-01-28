/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:36:29 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/28 14:03:18 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_images(t_game *game)
{
	game->frame = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->minimap_wall_img = mlx_texture_to_image(game->mlx, game->wall_texture);
	if (!game->minimap_wall_img)
		error_exit_and_free(game, "MLX failed to create wall image");
	game->minimap_floor_img = mlx_texture_to_image(game->mlx, game->floor_texture);
	if (!game->minimap_floor_img)
		error_exit_and_free(game, "MLX failed to create floor image");
	game->player.player_img = mlx_texture_to_image(game->mlx,
			game->player_texture);
	if (!game->player.player_img)
		error_exit_and_free(game, "MLX failed to create player image");
	game->minimap_img = mlx_new_image(game->mlx,
			MINIMAP_WIDTH, MINIMAP_HEIGHT);
}
