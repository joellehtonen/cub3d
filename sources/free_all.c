/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:52:26 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/03 10:07:04 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void free_array_of_strings(char ***arr)
{
	int i;

	i = 0;

	while ((*arr)[i])
		free((*arr)[i++]);
	free(*arr);
}

static void free_animation_textures(t_game *game)
{
	int	i;

	if (game->animation.zippo_texture)
		mlx_delete_texture(game->animation.zippo_texture);
	i = 0;
	while (i < 12)
	{
		if (game->animation.flame_texture[i])
			mlx_delete_texture(game->animation.flame_texture[i++]);
	}
}

static void	free_textures(t_game *game)
{
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
	free_animation_textures(game);
}

void	free_all(t_game *game)
{
	if (game->map)
		free_array_of_strings(&game->map);
	if (game->file)
		free_array_of_strings(&game->file);
	if (game->path_to_north_texture)
		free(game->path_to_north_texture);
	if (game->path_to_south_texture)
		free(game->path_to_south_texture);
	if (game->path_to_west_texture)
		free(game->path_to_west_texture);
	if (game->path_to_east_texture)
		free(game->path_to_east_texture);
	free_textures(game);
	//free_images(game);
	// if (game->frame)
	// 	mlx_delete_image(game->mlx, game->frame); // do we need to explicitly delete or mlx handles it upon destruction?
}
