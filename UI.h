#pragma once
#include <SFML/Graphics.hpp>

class blockdrawer
{
private:
    blockdrawer(){}
protected:
    static blockdrawer* instance;
public:
    blockdrawer(const int value){}
    static blockdrawer* getInstance()
    {
        if (!instance) instance = new blockdrawer;
        return instance;
    }
    blockdrawer(const blockdrawer& other) = delete;
    void operator=(const blockdrawer& other) = delete;
    void drawblock(sf::RenderWindow& w, int x, int y);
};

class boarddrawer
{
private:
    boarddrawer(){}
protected:
    static boarddrawer* instance;
public:
    boarddrawer(const int value){}
    static boarddrawer* getInstance()
    {
        if (!instance) instance = new boarddrawer;
        return instance;
    }
    boarddrawer(const boarddrawer& other) = delete;
    void operator=(const boarddrawer& other) = delete;

};