/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:30:46 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/28 21:19:36 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	//add checks
	game->north_texture = mlx_load_png("textures/path_to_north_texture.png");
	game->east_texture = mlx_load_png("textures/path_to_east_texture.png");
	game->south_texture = mlx_load_png("textures/path_to_south_texture.png");
	game->west_texture = mlx_load_png("textures/path_to_west_texture.png");
}
