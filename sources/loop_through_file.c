/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_through_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:05:00 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/22 11:51:08 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void check_for_path_or_rgb(t_game *game, int i, int *j)
{
	if (!ft_strncmp("NO ", (game->file)[i] + *j, 3))
		check_for_path(game, i, j, &game->path_to_north_texture);
	else if (!ft_strncmp("SO ", (game->file)[i] + *j, 3))
		check_for_path(game, i, j, &game->path_to_south_texture);
	else if (!ft_strncmp("WE ", (game->file)[i] + *j, 3))
		check_for_path(game, i, j, &game->path_to_west_texture);
	else if (!ft_strncmp("EA ", (game->file)[i] + *j, 3))
		check_for_path(game, i, j, &game->path_to_east_texture);
	else if (!ft_strncmp("F ", (game->file)[i] + *j, 2))
		check_for_rgb(game, i, j, FLOOR_RGB);
	else if (!ft_strncmp("C ", (game->file)[i] + *j, 2))
		check_for_rgb(game, i, j, CEILING_RGB);
}

static int found_all_paths_and_rgb(t_game *game)
{
	if (!game->path_to_north_texture ||
		!game->path_to_south_texture || 
		!game->path_to_west_texture ||
		!game->path_to_east_texture ||
		!game->found_floor_rgb ||
		!game->found_ceiling_rgb)
		return (0);
	return (1);
}

void loop_through_file(t_game *game, int *str_id)
{
	int should_break;
	int char_id;
	
	should_break = 0;
    while ((game->file)[*str_id])
	{
		char_id = 0;
		while ((game->file)[*str_id][char_id])
		{
			check_for_path_or_rgb(game, *str_id, &char_id);
			if (found_all_paths_and_rgb(game))
			{
				printf("break\n");
				should_break = 1;
				char_id = 0;
				break ;
			}
			char_id++;
		}
		if (should_break)
			break ;
		(*str_id)++;
	}	
}
