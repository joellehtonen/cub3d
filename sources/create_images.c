/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:36:29 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/14 11:46:48 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_images(t_game *game)
{
	game->wall_img = mlx_texture_to_image(game->mlx, game->wall_texture);
	if (!game->wall_img)
		error_exit_and_free(game, "MLX failed to create wall image");
	game->floor_img = mlx_texture_to_image(game->mlx, game->floor_texture);
	if (!game->floor_img)
		error_exit_and_free(game, "MLX failed to create floor image");
	// game->player->player_img = malloc(sizeof(mlx_image_t));
	// if (!game->player->player_img)
	// 	error_exit("Failed to malloc player image");
	game->player.player_img = mlx_texture_to_image(game->mlx, game->player_texture);
	if (!game->player.player_img)
		error_exit_and_free(game, "MLX failed to create player image");
}
