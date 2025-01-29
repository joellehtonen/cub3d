/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:30:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/29 18:11:58 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void create_torch_textures(t_game *game)
{
	int i;

	(game->torch_animation_textures)[0] = mlx_load_png("textures/torch/flame1.png");
	(game->torch_animation_textures)[1] = mlx_load_png("textures/torch/flame2.png");
	(game->torch_animation_textures)[2] = mlx_load_png("textures/torch/flame3.png");
	(game->torch_animation_textures)[3] = mlx_load_png("textures/torch/flame4.png");
	(game->torch_animation_textures)[4] = mlx_load_png("textures/torch/flame5.png");
	(game->torch_animation_textures)[5] = mlx_load_png("textures/torch/flame6.png");
	(game->torch_animation_textures)[6] = mlx_load_png("textures/torch/flame7.png");
	(game->torch_animation_textures)[7] = mlx_load_png("textures/torch/flame8.png");
	(game->torch_animation_textures)[8] = mlx_load_png("textures/torch/flame9.png");
	(game->torch_animation_textures)[9] = mlx_load_png("textures/torch/flame10.png");
	(game->torch_animation_textures)[10] = mlx_load_png("textures/torch/flame11.png");
	(game->torch_animation_textures)[11] = mlx_load_png("textures/torch/flame12.png");
	i = 0;
	while (i < 12)
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
	game->zippo_texture = mlx_load_png("textures/zippo.png");
	if (!game->zippo_texture)
		error_exit_and_free(game, "MLX failed to load player texture");
	create_torch_textures(game);
	//add checks
	game->north_texture = mlx_load_png("textures/path_to_north_texture.png");
	game->east_texture = mlx_load_png("textures/path_to_east_texture.png");
	game->south_texture = mlx_load_png("textures/path_to_south_texture.png");
	game->west_texture = mlx_load_png("textures/path_to_west_texture.png");
}
