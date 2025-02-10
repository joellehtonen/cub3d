/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:42:01 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/10 14:02:41 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	init_struct(t_line *line)
{
	line->dx = ft_abs(line->x2 - line->x1);
	line->dy = ft_abs(line->y2 - line->y1);
	if (line->x1 < line->x2)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y1 < line->y2)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
}

static void	bresenham_line(t_game *game, t_line line)
{
	init_struct(&line);
	while (1)
	{
		if (line.x1 > 0 && line.x1 < WINDOW_WIDTH
			&& line.y1 > 0 && line.y1 < WINDOW_HEIGHT)
			mlx_put_pixel(game->minimap.minimap_img,
				line.x1, line.y1, 0xff000088);
		if (line.x1 == line.x2 && line.y1 == line.y2)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 > -line.dy)
		{
			line.err -= line.dy;
			line.x1 += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			line.y1 += line.sy;
		}
	}
}

void	clear_line(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < (int)game->minimap.minimap_img->height)
	{
		x = 0;
		while (x < (int)game->minimap.minimap_img->width)
		{
			mlx_put_pixel(game->minimap.minimap_img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	draw_line(t_game *game)
{
	t_line	line;

	if (game->show_minimap == true)
	{
		line.x1 = game->player.x;
		line.y1 = game->player.y;
		line.x2 = (int)game->ray.x;
		line.y2 = (int)game->ray.y;
		bresenham_line(game, line);
	}
}
