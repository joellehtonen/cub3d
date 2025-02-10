/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:37:40 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/10 15:09:09 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	get_num_of_lines(char **file)
{
	int	result;

	result = 0;
	while (*file)
	{
		result++;
		file++;
	}
	return (result);
}

static void	remove_newlines(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '\n')
				game->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	copy_map(t_game *game, char **file)
{
	int	num_of_lines;
	int	i;

	num_of_lines = get_num_of_lines(file);
	game->map = (char **)malloc((num_of_lines + 1) * sizeof(char *));
	if (!game->map)
		error_exit_and_free(game, "Failed to malloc map");
	i = 0;
	while (file[i])
	{
		game->map[i] = ft_strdup(file[i]);
		if (!game->map[i])
			error_exit_and_free(game, "Failed to malloc map");
		i++;
	}
	game->map[i] = NULL;
	remove_newlines(game);
}
