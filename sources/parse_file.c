/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:19 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/30 15:21:41 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_for_path_or_rgb(t_game *game, int i, int *j)
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

static int	check_for_all_paths(t_game *game)
{
	if (!game->path_to_north_texture || !game->path_to_south_texture
		|| !game->path_to_west_texture || !game->path_to_east_texture)
		return (0);
	return (1);
}

static void	validate_rgb(t_game *game)
{
	if (game->floor_R < 0 || game->floor_R > 255
		|| game->floor_G < 0 || game->floor_G > 255
		|| game->floor_B < 0 || game->floor_B > 255
		|| game->ceiling_R < 0 || game->ceiling_R > 255
		|| game->ceiling_G < 0 || game->ceiling_G > 255
		|| game->ceiling_B < 0 || game->ceiling_B > 255)
		error_exit_and_free(game, "RGB missing or out of range");
}

static void	loop_through_file(t_game *game, int *i)
{
	int	j;
	int	break_while;

	break_while = 0;
	*i = 0;
	while ((game->file)[*i])
	{
		j = 0;
		while ((game->file)[*i][j])
		{
			check_for_path_or_rgb(game, *i, &j);
			if (check_for_all_paths(game) && game->found_floor_rgb
				&& game->found_ceiling_rgb)
			{
				break_while = 1;
				break ;
			}
			if ((game->file)[*i][j])
				j++;
		}
		(*i)++;
		if (break_while)
			break ;
	}
}

void	parse_file(t_game *game)
{
	int	i;

	loop_through_file(game, &i);
	if (!(check_for_all_paths(game)))
		error_exit_and_free(game, "Missing path to texture");
	validate_rgb(game);
	game->floor_RGB = (game->floor_R << 24) | (game->floor_G  << 16) | game->floor_B << 8 | 255;
	game->ceiling_RGB = (game->ceiling_R << 24) | (game->ceiling_G  << 16) | game->ceiling_B << 8 | 255;
	while (game->file[i][0] == '\n')
		i++;
	copy_map(game, game->file + i);
	validate_map(game);
	if (game->starting_direction == 0)
		error_exit_and_free(game, "Missing player on map");
}
