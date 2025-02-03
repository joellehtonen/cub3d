/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:36:29 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/03 16:39:37 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void create_torch_images(t_game *game)
{
	int i;

	i = 0;
	while (i < 12)
	{
		(game->animation.flame_img)[i] = mlx_texture_to_image(game->mlx, (game->animation.flame_texture)[i]);
		if (!(game->animation.flame_img)[i])
			error_exit_and_free(game, "MLX failed to create torch image");
		i++;
	}
}

void	create_images(t_game *game)
{
	game->frame = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->frame)
		error_exit_and_free(game, "MLX failed to create frame image");

	game->minimap.minimap_img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->minimap.minimap_img)
		error_exit_and_free(game, "MLX failed to create minimap image");
	game->animation.zippo_img = mlx_texture_to_image(game->mlx, game->animation.zippo_texture);
	if (!game->animation.zippo_img)
		error_exit_and_free(game, "MLX failed to create floor image");
	create_torch_images(game);
	if (game->show_minimap == true)
	{
		game->minimap.wall_img = mlx_texture_to_image(game->mlx, game->minimap.wall_texture);
		if (!game->minimap.wall_img)
			error_exit_and_free(game, "MLX failed to create wall image");
		game->minimap.floor_img = mlx_texture_to_image(game->mlx, game->minimap.floor_texture);
		if (!game->minimap.floor_img)
			error_exit_and_free(game, "MLX failed to create floor image");
		game->minimap.empty_map_img = mlx_texture_to_image(game->mlx, game->minimap.empty_map_texture);
		if (!game->minimap.empty_map_img)
			error_exit_and_free(game, "MLX failed to create empty_map image");
		game->minimap.player_img = mlx_texture_to_image(game->mlx, game->minimap.player_texture);
		if (!game->minimap.player_img)
			error_exit_and_free(game, "MLX failed to create player image");		
	}
	else
	{
		game->minimap.wall_img = mlx_new_image(game->mlx, game->tile_size, game->tile_size);
		if (!game->minimap.wall_img)
			error_exit_and_free(game, "MLX failed to create wall image");
		game->minimap.floor_img = mlx_new_image(game->mlx, game->tile_size, game->tile_size);
		if (!game->minimap.floor_img)
			error_exit_and_free(game, "MLX failed to create floor image");
		game->minimap.empty_map_img = mlx_new_image(game->mlx, game->tile_size, game->tile_size);
		if (!game->minimap.empty_map_img)
			error_exit_and_free(game, "MLX failed to create empty_map image");
		game->minimap.player_img = mlx_new_image(game->mlx, game->tile_size / 4, game->tile_size / 4);
		if (!game->minimap.player_img)
			error_exit_and_free(game, "MLX failed to create player image");
	}
}
