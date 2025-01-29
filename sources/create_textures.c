/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:30:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/28 14:52:34 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void create_torch_textures(t_game *game)
{
	int i;

	(game->torch_animation_textures)[0] = mlx_load_png("textures/torch/frame_01.png");
	(game->torch_animation_textures)[1] = mlx_load_png("textures/torch/frame_01.png");
	(game->torch_animation_textures)[2] = mlx_load_png("textures/torch/frame_02.png");
	(game->torch_animation_textures)[3] = mlx_load_png("textures/torch/frame_03.png");
	(game->torch_animation_textures)[4] = mlx_load_png("textures/torch/frame_04.png");
	(game->torch_animation_textures)[5] = mlx_load_png("textures/torch/frame_05.png");
	(game->torch_animation_textures)[6] = mlx_load_png("textures/torch/frame_06.png");
	(game->torch_animation_textures)[7] = mlx_load_png("textures/torch/frame_07.png");
	i = 0;
	while (i < 8)
	{
		if (!((game->torch_animation_textures)[i]))
			error_exit_and_free(game, "MLX failed to load torch texture");
		i++;
	}
}

void	create_textures(t_game *game)
{
	game->wall_texture = mlx_load_png("textures/wall.png");
	if (!game->wall_texture)
		error_exit_and_free(game, "MLX failed to load wall texture");
	game->floor_texture = mlx_load_png("textures/floor.png");
	if (!game->floor_texture)
		error_exit_and_free(game, "MLX failed to load floor texture");
	game->player_texture = mlx_load_png("textures/player.png");
	if (!game->player_texture)
		error_exit_and_free(game, "MLX failed to load player texture");
	create_torch_textures(game);
}
