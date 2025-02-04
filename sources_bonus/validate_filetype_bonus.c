/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_filetype_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:15:06 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:26 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	validate_filetype(char *filename)
{
	while (*filename)
	{
		if (*filename == '.')
		{
			if (ft_strncmp(filename, ".cub", 5))
				error_exit("Invalid File: Invalid filetype");
		}
		filename++;
	}
}
