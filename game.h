#pragma once
#include "board.h"

class game
{
private:
    std::vector<std::vector<board>> gameboard;
    board result;
public:
    game();
    void convertto3x3();
    void play(player& p, int row, int col);
    void show();
    void handleendofmove(int row, int col);
    bool finished();
};
