#include <unistd.h>

int arr[50][50];

int any(int x, int y)
{
    if (arr[y][x])
        return (1);
    return (0);
}

void put(int x, int y)
{
    arr[y][x] = 1;
}

void draw(void)
{
    int cx = 0, cy = 0;
    while (cy++ < 50)
    {
        while (cx++ < 50)
        {
            if (any(cx, cy))
                write(1, "X", 1);
            else
                write(1, " ", 1);
        }
        write(1, "\n", 1);
        cx = 0;
    }
}

