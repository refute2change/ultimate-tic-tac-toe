#include "board.h"

board::board()
{
    for (int i = 0; i < 3; i++)
    {
        theboard.push_back(std::vector<block>());
        for (int j = 0; j < 3; j++) theboard[i].push_back(block::empty);
    }
}

void board::play(player& p, int row, int col)
{
    if (!playable) return;
    if (row < 0 || row > 3) return;
    if (col < 0 || col > 3) return;
    if (theboard[row][col] != block::empty) return;
    
    else if (p == player::pX)
    {
        theboard[row][col] = block::X;
        p = player::pO;
        played = true;
    }
    else if (p == player::pO)
    {
        theboard[row][col] = block::O;
        p = player::pX;
        played = true;
    }
}

bool board::Xwin()
{
    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++) if (theboard[i][j] != block::X) break;
        if (j == 3) return true;
    }
    for (int i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++) if (theboard[j][i] != block::X) break;
        if (j == 3) return true;
    }
    if (theboard[0][2] == block::X && theboard[1][1] == block::X && theboard[2][0] == block::X) return true;
    if (theboard[0][0] == block::X && theboard[1][1] == block::X && theboard[2][2] == block::X) return true;
    return false;
}

bool board::Owin()
{
    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++) if (theboard[i][j] != block::O) break;
        if (j == 3) return true;
    }
    for (int i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++) if (theboard[j][i] != block::O) break;
        if (j == 3) return true;
    }
    if (theboard[0][2] == block::O && theboard[1][1] == block::O && theboard[2][0] == block::O) return true;
    if (theboard[0][0] == block::O && theboard[1][1] == block::O && theboard[2][2] == block::O) return true;
    return false;
}

int board::result()
{
    if (Xwin()) return 1;
    if (Owin()) return -1;
    return 0;
}

block board::blockresult()
{
    block res[3] = {block::O, block::empty, block::X};
    return res[result() + 1];
}

block board::getblock(int i, int j)
{
    return theboard[i][j];
}

void board::show()
{
    for (int i = 0; i < 3; i++) 
    {
        std::cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            switch (getblock(i, j))
            {
            case block::empty:
                std::cout << " ";
                break;
            case block::X:
                std::cout << "X";
                break;
            case block::O:
                std::cout << "O";
                break;
            default:
                break;
            }
            std::cout << " | ";
        }
        std::cout << '\n';
    }
}

void board::showrow(int row)
{
    if (finished())
    {
        if (Xwin()) SetConsoleTextAttribute(hConsole, 12);
        else if (Owin()) SetConsoleTextAttribute(hConsole, 11);
        else SetConsoleTextAttribute(hConsole, 8);
    }
    else if (playable) SetConsoleTextAttribute(hConsole, 10);
    else SetConsoleTextAttribute(hConsole, 15);
    std::cout << "| ";
    for (int j = 0; j < 3; j++)
    {
        switch (getblock(row, j))
        {
        case block::empty:
            std::cout << " ";
            break;
        case block::X:
            std::cout << "X";
            break;
        case block::O:
            std::cout << "O";
            break;
        default:
            break;
        }
        std::cout << " | ";
    }
    SetConsoleTextAttribute(hConsole, 15);
}

bool board::finished()
{
    if (result() != 0) return true;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) if (theboard[i][j] == block::empty) return false;
    return true;
}

