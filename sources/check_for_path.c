/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:48:28 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/11 14:30:55 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_path_length(int j, char *fileline)
{
	int	result;

	result = 0;
	while (fileline[j])
	{
		if (fileline[j] == ' ' || fileline[j] == '\t' || fileline[j] == '\n')
			return (result);
		result++;
		j++;
	}
	return (result);
}

static void	copy_path(int j, char *fileline, char **path)
{
	int	i;

	i = 0;
	while (fileline[j])
	{
		if (fileline[j] == ' ' || fileline[j] == '\t' || fileline[j] == '\n')
			break ;
		(*path)[i] = fileline[j];
		i++;
		j++;
	}
	(*path)[i] = '\0';
}

void	check_for_path(t_game *game, int i, int *j, char **path)
{
	int	path_length;

	if (*path)
		error_exit_and_free(game, "Duplicate paths to textures");
	*j += 3;
	while (game->file[i][*j] == ' ')
		(*j)++;
	path_length = get_path_length(*j, game->file[i]);
	if (!path_length)
		error_exit_and_free(game, "Given map is missing a path to texture");
	*path = (char *)malloc(path_length + 1);
	if (!*path)
		error_exit_and_free(game, "Failed to malloc path to texture");
	copy_path(*j, game->file[i], path);
	*j += path_length;
}
