/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:36:29 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/11 13:32:21 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	create_torch_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		(game->animation.flame_img)[i] = mlx_texture_to_image(game->mlx,
				(game->animation.flame_t)[i]);
		if (!(game->animation.flame_img)[i])
			error_exit_and_free(game, "MLX failed to create torch image");
		i++;
	}
}

static void	images_for_minimap(t_game *game)
{
	game->minimap.wall_img = mlx_texture_to_image(game->mlx,
			game->minimap.wall_texture);
	if (!game->minimap.wall_img)
		error_exit_and_free(game, "MLX failed to create wall image");
	game->minimap.floor_img = mlx_texture_to_image(game->mlx,
			game->minimap.floor_texture);
	if (!game->minimap.floor_img)
		error_exit_and_free(game, "MLX failed to create floor image");
	game->minimap.empty_map_img = mlx_texture_to_image(game->mlx,
			game->minimap.empty_map_texture);
	if (!game->minimap.empty_map_img)
		error_exit_and_free(game, "MLX failed to create empty_map image");
	game->minimap.player_img = mlx_texture_to_image(game->mlx,
			game->minimap.player_texture);
	if (!game->minimap.player_img)
		error_exit_and_free(game, "MLX failed to create player image");
	game->minimap.closed_door_img = mlx_texture_to_image(game->mlx,
			game->minimap.closed_door_texture);
	if (!game->minimap.closed_door_img)
		error_exit_and_free(game, "MLX failed to create closed door image");
	game->minimap.open_door_img = mlx_texture_to_image(game->mlx,
			game->minimap.floor_texture);
	if (!game->minimap.open_door_img)
		error_exit_and_free(game, "MLX failed to create open door image");
}

static void	disable_minimap_images(t_game *game)
{
	game->minimap.wall_img->enabled = false;
	game->minimap.floor_img->enabled = false;
	game->minimap.empty_map_img->enabled = false;
	game->minimap.player_img->enabled = false;
	game->minimap.closed_door_img->enabled = false;
	game->minimap.open_door_img->enabled = false;
}

void	create_images(t_game *game)
{
	game->frame = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->frame)
		error_exit_and_free(game, "MLX failed to create frame image");
	game->minimap.minimap_img = mlx_new_image(game->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->minimap.minimap_img)
		error_exit_and_free(game, "MLX failed to create minimap image");
	game->animation.zippo_img = mlx_texture_to_image(game->mlx,
			game->animation.zippo_texture);
	if (!game->animation.zippo_img)
		error_exit_and_free(game, "MLX failed to create floor image");
	create_torch_images(game);
	images_for_minimap(game);
	if (game->show_minimap == false)
		disable_minimap_images(game);
}
