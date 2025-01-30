/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:30:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/30 10:48:31 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void create_torch_textures(t_game *game)
{
	int i;

	(game->flame_texture)[0] = mlx_load_png("textures/torch/flame1.png");
	(game->flame_texture)[1] = mlx_load_png("textures/torch/flame2.png");
	(game->flame_texture)[2] = mlx_load_png("textures/torch/flame3.png");
	(game->flame_texture)[3] = mlx_load_png("textures/torch/flame4.png");
	(game->flame_texture)[4] = mlx_load_png("textures/torch/flame5.png");
	(game->flame_texture)[5] = mlx_load_png("textures/torch/flame6.png");
	(game->flame_texture)[6] = mlx_load_png("textures/torch/flame7.png");
	(game->flame_texture)[7] = mlx_load_png("textures/torch/flame8.png");
	(game->flame_texture)[8] = mlx_load_png("textures/torch/flame9.png");
	(game->flame_texture)[9] = mlx_load_png("textures/torch/flame10.png");
	(game->flame_texture)[10] = mlx_load_png("textures/torch/flame11.png");
	(game->flame_texture)[11] = mlx_load_png("textures/torch/flame12.png");
	i = 0;
	while (i < 12)
	{
		if (!((game->flame_texture)[i]))
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
	game->zippo_texture = mlx_load_png("textures/zippo_cartoon.png");
	if (!game->zippo_texture)
		error_exit_and_free(game, "MLX failed to load player texture");
	create_torch_textures(game);
	//add checks
	// game->north_texture = mlx_load_png("textures/path_to_north_texture.png");
	// game->east_texture = mlx_load_png("textures/path_to_east_texture.png");
	// game->south_texture = mlx_load_png("textures/path_to_south_texture.png");
	// game->west_texture = mlx_load_png("textures/path_to_west_texture.png");
	// game->north_texture = mlx_load_png("textures/Brick_Wall_Brown.png");
	// game->east_texture = mlx_load_png("textures/Brick_Wall_Grey.png");
	// game->south_texture = mlx_load_png("textures/Brick_Wall_Red.png");
	// game->west_texture = mlx_load_png("textures/Old_Brick_Wall.png");
	game->north_texture = mlx_load_png("textures/Impression_Sunrise.png");
	game->east_texture = mlx_load_png("textures/Sunflowers.png");
	game->south_texture = mlx_load_png("textures/Wheat_Field.png");
	game->west_texture = mlx_load_png("textures/the_starry_night.png");
}
