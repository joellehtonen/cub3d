/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:19 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/11 14:05:28 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	validate_rgb(t_game *game)
{
	if (game->floor_r < 0 || game->floor_r > 255
		|| game->floor_g < 0 || game->floor_g > 255
		|| game->floor_b < 0 || game->floor_b > 255
		|| game->ceiling_r < 0 || game->ceiling_r > 255
		|| game->ceiling_g < 0 || game->ceiling_g > 255
		|| game->ceiling_b < 0 || game->ceiling_b > 255)
		error_exit_and_free(game, "RGB missing or out of range");
}

static void	free_map_in_middle(t_game *game, int i)
{
	i++;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
}

static void	fill_in_gaps_for_map(t_game *game)
{
	int		i;
	char	*temp;

	temp = NULL;
	i = 0;
	while (game->map[i])
	{
		while ((int)ft_strlen(game->map[i]) < game->width_in_tiles)
		{
			temp = ft_strdup(game->map[i]);
			if (!temp)
				error_exit_and_free(game, "Failed to malloc gaps for map");
			free(game->map[i]);
			game->map[i] = NULL;
			game->map[i] = ft_strjoin(temp, ".");
			if (!game->map[i])
			{
				free_map_in_middle(game, i);
				error_exit_and_free(game, "Failed to malloc gaps for map");
			}
			free(temp);
			temp = NULL;
		}
		i++;
	}
}

void	parse_file(t_game *game)
{
	int	i;

	get_paths_and_rgb(game, &i);
	if (!(check_for_all_paths(game)))
		error_exit_and_free(game, "Missing path to texture");
	validate_rgb(game);
	game->floor_rgb = ((unsigned int)game->floor_r << 24) | \
	((unsigned int)game->floor_g << 16) | \
	(unsigned int)game->floor_b << 8 | 255;
	game->ceiling_rgb = ((unsigned int)game->ceiling_r << 24) | \
	((unsigned int)game->ceiling_g << 16) | \
	(unsigned int)game->ceiling_b << 8 | 255;
	while (game->file[i] && game->file[i][0] == '\n')
		i++;
	copy_map(game, game->file + i);
	validate_map(game);
	fill_in_gaps_for_map(game);
	if (game->starting_direction == 0)
		error_exit_and_free(game, "Missing player on map");
}
