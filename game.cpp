#include "game.h"

game::game()
{
    for (int i = 0; i < 3; i++)
    {
        gameboard.push_back(std::vector<board>());
        for (int j = 0; j < 3; j++) gameboard[i].push_back(board());
    }
}

void game::convertto3x3()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) resultboard.setblock(i, j, gameboard[i][j].blockresult());
}

void game::play(player& p, int row, int col)
{
    if (row < 0 || row > 8) return;
    if (col < 0 || col > 8) return;
    gameboard[row / 3][col / 3].play(p, row % 3, col % 3);
    handleendofmove(row, col);
}

void game::show()
{
    for (int i = 0; i < 3; i++)
    {
        for (int row = 0; row < 3; row++)
        {
            for (int j = 0; j < 3; j++) gameboard[i][j].showrow(row);
            std::cout << '\n';
        }
        if (i != 2) std::cout << "\n";
    }
}

bool game::finished()
{
    if (resultboard.Xwin() || resultboard.Owin()) return true;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (!gameboard[i][j].finished()) return false;
    return true;
}

void game::handleendofmove(int row, int col)
{
    if (!gameboard[row / 3][col / 3].played) return;
    gameboard[row/3][col/3].played = false;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) gameboard[i][j].playable = false;
    if (!gameboard[row % 3][col % 3].finished()) gameboard[row % 3][col % 3].playable = true;
    else for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (!gameboard[i][j].finished()) gameboard[i][j].playable = true;
}   