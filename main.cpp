#include "game.h"

int main()
{
    game g;
    player p = player::pX;
    g.show();
    int a, b;
    while (!g.finished())
    {
        std::cin >> a >> b;
        g.play(p, a, b);
        g.convertto3x3();
        g.show();
    }
    return 0;
}