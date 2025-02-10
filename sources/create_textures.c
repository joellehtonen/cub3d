/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:30:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/04 16:30:20 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_textures(t_game *game)
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
}
