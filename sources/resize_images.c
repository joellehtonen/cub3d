/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:42:02 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/14 11:48:01 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	resize_images(t_game *game)
{
	if (!mlx_resize_image(game->wall_img, game->image_size, game->image_size))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->floor_img, game->image_size, game->image_size))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->player.player_img, game->image_size/4, game->image_size/4))
		error_exit_and_free(game, "MLX failed to resize an image");
}
