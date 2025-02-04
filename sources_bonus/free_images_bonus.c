/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:05:46 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:12 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	free_animation_images(t_game *game)
{
	int	i;

	if (game->animation.zippo_img)
		mlx_delete_image(game->mlx, game->animation.zippo_img);
	if (game->animation.flame_mem_img)
		mlx_delete_image(game->mlx, game->animation.flame_mem_img);
	i = 0;
	while (i < 12)
	{
		if (game->animation.flame_img[i])
			mlx_delete_image(game->mlx, game->animation.flame_img[i]);
		i++;
	}
}

void	free_images(t_game *game)
{
	free_animation_images(game);
	if (game->frame)
		mlx_delete_image(game->mlx, game->frame);
	if (game->door_warning)
		mlx_delete_image(game->mlx, game->door_warning);
	if (game->minimap.wall_img)
		mlx_delete_image(game->mlx, game->minimap.wall_img);
	if (game->minimap.floor_img)
		mlx_delete_image(game->mlx, game->minimap.floor_img);
	if (game->minimap.empty_map_img)
		mlx_delete_image(game->mlx, game->minimap.empty_map_img);
	if (game->minimap.player_img)
		mlx_delete_image(game->mlx, game->minimap.player_img);
	if (game->minimap.minimap_img)
		mlx_delete_image(game->mlx, game->minimap.minimap_img);
}

static void	free_animation_textures(t_game *game)
{
	int	i;

	if (game->animation.zippo_texture)
		mlx_delete_texture(game->animation.zippo_texture);
	i = 0;
	while (i < 12)
	{
		if (game->animation.flame_texture[i])
			mlx_delete_texture(game->animation.flame_texture[i]);
		i++;
	}
}

void	free_textures(t_game *game)
{
	free_animation_textures(game);
	if (game->north_texture)
		mlx_delete_texture(game->north_texture);
	if (game->east_texture)
		mlx_delete_texture(game->east_texture);
	if (game->south_texture)
		mlx_delete_texture(game->south_texture);
	if (game->west_texture)
		mlx_delete_texture(game->west_texture);
	if (game->door_texture)
		mlx_delete_texture(game->door_texture);
	if (game->minimap.floor_texture)
		mlx_delete_texture(game->minimap.floor_texture);
	if (game->minimap.wall_texture)
		mlx_delete_texture(game->minimap.wall_texture);
	if (game->minimap.player_texture)
		mlx_delete_texture(game->minimap.player_texture);
	if (game->minimap.empty_map_texture)
		mlx_delete_texture(game->minimap.empty_map_texture);
}
