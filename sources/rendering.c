#include "../includes/cub3d.h"

void rendering(void * content)
{
    t_game *game;
    game = (t_game *)content;

    controls(game);
    raycasting(game);
}