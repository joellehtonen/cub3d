/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:42:01 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/23 11:41:45 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void bresenham_line(t_game *game, int x1, int y1, int x2, int y2)
{
    int dx = ft_abs(x2 - x1);
    int dy = ft_abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
		if (x1 > 0 && x1 < WINDOW_HEIGHT && y1 > 0 && y1 < WINDOW_HEIGHT)
        	mlx_put_pixel(game->minimap_img, x1, y1, 0xff0000ff);
        
        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

static void clear_line(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < (int)game->minimap_img->height)
	{
		x = 0;
		while (x < (int)game->minimap_img->width)
		{
			mlx_put_pixel(game->minimap_img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void draw_line(t_game *game)
{
	//printf("game_ray_x = %f and %d, game_ray_y = %f and %d\n", game->ray.x, (int)game->ray.x, game->ray.y, (int)game->ray.y);
	clear_line(game);
    bresenham_line(game, game->player.x, game->player.y, (int)game->ray.x, (int)game->ray.y);
	//bresenham_line(game, game->player.x, game->player.y, game->player.x, game->player.y - 100);
	
}
