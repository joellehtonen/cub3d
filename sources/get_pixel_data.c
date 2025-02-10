/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:22:12 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 19:03:33 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	@brief Gets pixel color data (red, green, blue and alpha)
	 from the pixel at the given location.
	@param *texture Texture where pixel is located
	@param *rgba Reference to the color variable
	@param location Location of the pixel
*/
void	extract_color_data(mlx_texture_t *texture, uint32_t *rgba, \
	unsigned int location)
{
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint8_t		alpha;

	if (location + 3 >= (texture->width * texture->height * 4))
		return ;
	red = texture->pixels[location];
	green = texture->pixels[location + 1];
	blue = texture->pixels[location + 2];
	alpha = texture->pixels[location + 3];
	*rgba = (red << 24) | (green << 16) | (blue << 8) | (alpha);
	return ;
}
