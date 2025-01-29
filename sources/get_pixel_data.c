/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:22:12 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/29 17:49:43 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

uint32_t	extract_color_data(mlx_texture_t *texture, int location)
{
	uint8_t 	red;
	uint8_t 	green;
	uint8_t 	blue;
	uint8_t 	alpha;
	uint32_t 	rgba;

	blue = texture->pixels[location];
	green = texture->pixels[location + 1];
	red = texture->pixels[location + 2];
	alpha = texture->pixels[location + 3];
	rgba = (red << 24) | (green << 16) | (blue << 8) | (alpha);
	//printf("pixel at 0,0 - r: %d, g: %d, b: %d, alpha: %d\n", red, green, blue, alpha);
	return (rgba);
}
