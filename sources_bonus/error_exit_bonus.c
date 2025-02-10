/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:15:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:11 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	error_exit_and_free(t_game *game, char *error)
{
	free_all(game);
	printf("Error\n%s\n", error);
	exit (1);
}

void	error_exit(char *error)
{
	printf("Error\n%s\n", error);
	exit (1);
}
