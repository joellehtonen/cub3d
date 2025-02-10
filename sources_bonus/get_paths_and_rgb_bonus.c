/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths_and_rgb_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:32:55 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/10 13:34:45 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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

int	check_for_all_paths(t_game *game)
{
	if (!game->path_to_north_texture || !game->path_to_south_texture
		|| !game->path_to_west_texture || !game->path_to_east_texture)
		return (0);
	return (1);
}

void	get_paths_and_rgb(t_game *game, int *i)
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
