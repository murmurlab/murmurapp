#include "minilibx_macos/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct g_game
{
    void *mlx_p;
    void *win_p;
    float delta_x;
    float delta_y;
    float m;
    float n;
    int x1;
    int x2;
    int y1;
    int y2;
}       t_game;

t_game game;
// y = mx + n;

int mehmet(void *mlx_p, void *win_p)
{
    int c;
    int y;

    write(1, "xxx", 3);
    c = game.x1;
    while(c < game.x2)
    {
        y = (game.m * c) + game.n;
        mlx_pixel_put(mlx_p, win_p, c, y, 0x00ffffff);
        c++;
    }
    printf("0000");
    return (0);
}

int ahmet(void *mlx_p, void *win_p)
{
    int c;
    int x;

    write(1, "aaa", 3);
    c = game.y1;
    while(c < game.y2)
    {
        x = (c - game.n) / (game.m);
        mlx_pixel_put(mlx_p, win_p, x, c, 0x00ffffff);
        c++;
    }
    printf("0000");
    return (0);
}

int line(int x1, int y1, int x2, int y2, t_game *game)
{
    game->x1 = x1;
    game->x2 = x2;
    game->y1 = y1;
    game->y2 = y2;
    game->delta_x = abs(x1 - x2);
    game->delta_y = abs(y1 - y2);
    game->m = game->delta_y / game->delta_x;
    game->n = (-game->m * x2) + y2;
    // n = -(mx - y)
    // y = mx + n;
    if (game->delta_x > game->delta_y)
        mehmet(game->mlx_p, game->win_p);
    else
        ahmet(game->mlx_p, game->win_p);
    return (1);
}

int main(int argc, char const *argv[])
{
    game.mlx_p = mlx_init();
    game.win_p = mlx_new_window(game.mlx_p, 100, 100, "title");
    // while(1);
    line(0, 0, 65, 78, &game);
    mlx_loop(game.mlx_p);
    return (0);
}


// y = mx + n;
// y - n = mx
// (y - n) / m = x