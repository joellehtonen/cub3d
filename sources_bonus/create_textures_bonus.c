/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:30:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:05 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void create_torch_textures(t_game *game)
{
	int i;

	(game->animation.flame_texture)[0] = mlx_load_png("textures/flame/flame1.png");
	(game->animation.flame_texture)[1] = mlx_load_png("textures/flame/flame2.png");
	(game->animation.flame_texture)[2] = mlx_load_png("textures/flame/flame3.png");
	(game->animation.flame_texture)[3] = mlx_load_png("textures/flame/flame4.png");
	(game->animation.flame_texture)[4] = mlx_load_png("textures/flame/flame5.png");
	(game->animation.flame_texture)[5] = mlx_load_png("textures/flame/flame6.png");
	(game->animation.flame_texture)[6] = mlx_load_png("textures/flame/flame7.png");
	(game->animation.flame_texture)[7] = mlx_load_png("textures/flame/flame8.png");
	(game->animation.flame_texture)[8] = mlx_load_png("textures/flame/flame9.png");
	(game->animation.flame_texture)[9] = mlx_load_png("textures/flame/flame10.png");
	(game->animation.flame_texture)[10] = mlx_load_png("textures/flame/flame11.png");
	(game->animation.flame_texture)[11] = mlx_load_png("textures/flame/flame12.png");
	i = 0;
	while (i < 12)
	{
		if (!((game->animation.flame_texture)[i]))
			error_exit_and_free(game, "MLX failed to load torch texture");
		i++;
	}
}

static void create_minimap_textures(t_game *game)
{
	game->minimap.wall_texture = mlx_load_png("textures/wall.png");
	if (!game->minimap.wall_texture)
		error_exit_and_free(game, "MLX failed to load wall texture");
	game->minimap.floor_texture = mlx_load_png("textures/floor.png");
	if (!game->minimap.floor_texture)
		error_exit_and_free(game, "MLX failed to load floor texture");
	game->minimap.player_texture = mlx_load_png("textures/player.png");
	if (!game->minimap.player_texture)
		error_exit_and_free(game, "MLX failed to load player texture");
}

static void create_wall_textures(t_game *game)
{
	game->north_texture = mlx_load_png(game->path_to_north_texture);
	if (!game->north_texture)
		error_exit_and_free(game, "MLX failed to load north texture");
	game->east_texture = mlx_load_png(game->path_to_east_texture);
	if (!game->east_texture)
		error_exit_and_free(game, "MLX failed to load east texture");
	game->south_texture = mlx_load_png(game->path_to_south_texture);
	if (!game->south_texture)
		error_exit_and_free(game, "MLX failed to load south texture");
	game->west_texture = mlx_load_png(game->path_to_west_texture);
	if (!game->west_texture)
		error_exit_and_free(game, "MLX failed to load west texture");	
	game->door_texture = mlx_load_png("textures/the_scream.png");
	if (!game->door_texture)
		error_exit_and_free(game, "MLX failed to load door texture");
}

void	create_textures(t_game *game)
{
	create_torch_textures(game);
	create_wall_textures(game);
	if (game->show_minimap == true)
		create_minimap_textures(game);
	game->minimap.empty_map_texture = mlx_load_png("textures/empty_map.png");
	if (!game->minimap.empty_map_texture)
		error_exit_and_free(game, "MLX failed to load empty_map texture");
	game->animation.zippo_texture = mlx_load_png("textures/zippo_cartoon.png");
	if (!game->animation.zippo_texture)
		error_exit_and_free(game, "MLX failed to load zippo texture");	
}
