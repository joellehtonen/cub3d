/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:16:19 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/15 14:33:31 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void add_value(t_game *game, int i, int *j, int *element)
{
	*element = ft_atoi(game->file[i] + *j);
	while (game->file[i][*j] != ',' && game->file[i][*j] != ' ' && game->file[i][*j] != '\0')
		(*j)++;
	if (game->file[i][*j])
		(*j)++;
}

void check_for_rgb(t_game *game, int i, int *j, int element)
{
	if ((element == FLOOR_RGB && game->found_floor_rgb)
		|| (element == CEILING_RGB && game->found_ceiling_rgb))
		error_exit_and_free(game, "Duplicate RGB for floor or ceiling");
	if (element == FLOOR_RGB)
		game->found_floor_rgb = 1;
	else
		game->found_ceiling_rgb = 1;
	*j += 2;
	if (element == FLOOR_RGB)
	{
		add_value(game, i, j, &game->floor_R);
		add_value(game, i, j, &game->floor_G);
		add_value(game, i, j, &game->floor_B);
	}
	else
	{
		add_value(game, i, j, &game->ceiling_R);
		add_value(game, i, j, &game->ceiling_G);
		add_value(game, i, j, &game->ceiling_B);
	}
}
