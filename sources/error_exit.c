/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:15:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/13 16:10:13 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cu3ed.h"

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
