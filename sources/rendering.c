#include "../includes/cub3d.h"

void rendering(void * content)
{
    t_game  *game;
    game =  (t_game *)content;
    bool     movement;

    movement = controls(game);
    if (movement == true)
    {
        raycasting(game);
        draw_line(game);
    }
}
