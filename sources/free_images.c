/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:05:46 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 19:04:25 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_images(t_game *game)
{
	if (game->frame)
		mlx_delete_image(game->mlx, game->frame);
}

void	free_textures(t_game *game)
{
	if (game->north_texture)
		mlx_delete_texture(game->north_texture);
	if (game->east_texture)
		mlx_delete_texture(game->east_texture);
	if (game->south_texture)
		mlx_delete_texture(game->south_texture);
	if (game->west_texture)
		mlx_delete_texture(game->west_texture);
}
