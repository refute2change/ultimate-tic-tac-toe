#include "game.h"
#include <stdlib.h>

int main()
{
    game g;
    player p = player::pX;
    system("cls");
    g.show();
    int a, b;
    while (!g.finished())
    {
        std::cin >> a >> b;
        g.play(p, a, b);
        g.convertto3x3();
        system("cls");
        g.show();
    }
    if (g.result() == 1) std::cout << "X won.\n";
    else if (g.result() == -1) std::cout << "O won.\n";
    else std::cout << "Game tied.\n";
    return 0;
}