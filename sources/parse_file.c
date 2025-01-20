/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:19 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/20 12:23:02 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void check_for_path_or_rgb(t_game *game, int i, int *j)
{
	if (!ft_strncmp("NO ./", (game->file)[i] + *j, 5))
		check_for_path(game, i, j, &game->path_to_north_texture);
	if (!ft_strncmp("SO ./", (game->file)[i] + *j, 5))
		check_for_path(game, i, j, &game->path_to_south_texture);
	if (!ft_strncmp("WE ./", (game->file)[i] + *j, 5))
		check_for_path(game, i, j, &game->path_to_west_texture);
	if (!ft_strncmp("EA ./", (game->file)[i] + *j, 5))
		check_for_path(game, i, j, &game->path_to_east_texture);
	if (!ft_strncmp("F ", (game->file)[i] + *j, 2))
		check_for_rgb(game, i, j, FLOOR_RGB);
	if (!ft_strncmp("C ", (game->file)[i] + *j, 2))
		check_for_rgb(game, i, j, CEILING_RGB);
}

static void print_paths_and_rgb(t_game *game) //REMOVE
{
	printf("NO = %s\n", game->path_to_north_texture);
	printf("SO = %s\n", game->path_to_south_texture);
	printf("WE = %s\n", game->path_to_west_texture);
	printf("EA = %s\n", game->path_to_east_texture);
	printf("F  = %d,%d,%d\n", game->floor_R, game->floor_G, game->floor_B);
	printf("C  = %d,%d,%d\n", game->ceiling_R, game->ceiling_G, game->ceiling_B);
}

void    parse_file(t_game *game)
{
	int i;
	int j;

	i = 0;
    while ((game->file)[i])
	{
		j = 0;
		while ((game->file)[i][j])
		{
			check_for_path_or_rgb(game, i, &j);
			j++;
		}
		i++;
	}
	print_paths_and_rgb(game); //REMOVE
}
