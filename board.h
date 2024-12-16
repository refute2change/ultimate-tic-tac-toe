#pragma once
#include <vector>
#include "definition.h"
#include <iostream>
#include <windows.h>

class board
{
private:
    std::vector<std::vector<block>> theboard;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:
    bool playable = true, played = false;
    board();
    void play(player& p, int row, int col);
    void setblock(int row, int col, block value)
    {
        theboard[row][col] = value;
    }
    std::vector<block>& operator[](int index)
    {
        if (index > 3) exit(0);
        return theboard[index];
    }
    bool Xwin();
    bool Owin();
    int result();
    void show();
    void showrow(int row);
    block getblock(int i, int j);
    block blockresult();
    bool finished();
};