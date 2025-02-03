/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:22:12 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/03 16:54:20 by jlehtone         ###   ########.fr       */
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

	if (location < 0 || location + 3 >= (texture->width * texture->height * 4))
		return (0);
	red = texture->pixels[location];
	green = texture->pixels[location + 1];
	blue = texture->pixels[location + 2];
	alpha = texture->pixels[location + 3];
	*rgba = (red << 24) | (green << 16) | (blue << 8) | (alpha);
	return ;
}

/*
	@brief Gets pixel color data (red, green, blue and alpha)
	 from the pixel at the given location, and turns it black and white.
	@param *texture Texture where pixel is located
	@param *rgba Reference to the color variable
	@param location Location of the pixel
*/
void	extract_color_data_dark(mlx_texture_t *texture, \
	uint32_t *rgba, unsigned int location)
{
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint8_t		alpha;
	uint8_t		gray;

	if (location < 0 || location + 3 >= (texture->width * texture->height * 4))
		return (0);
	red = texture->pixels[location];
	green = texture->pixels[location + 1];
	blue = texture->pixels[location + 2];
	alpha = texture->pixels[location + 3];
	gray = 0.299 * red + 0.587 * green + 0.114 * blue;
	red = gray;
	green = gray;
	blue = gray;
	*rgba = (red << 24) | (green << 16) | (blue << 8) | (alpha);
	return ;
}
