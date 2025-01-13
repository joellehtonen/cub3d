/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:52:26 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/13 16:02:16 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cu3ed.h"

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
	if (game->floor_rgb)
		free(game->floor_rgb);
	if (game->ceiling_rgb)
		free(game->ceiling_rgb);
}
