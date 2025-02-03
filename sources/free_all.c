/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:52:26 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/03 16:25:15 by jlehtone         ###   ########.fr       */
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
	free_images(game);
	// if (game->mlx->window)
	// 	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
}
