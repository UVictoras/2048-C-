// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

class Case
{
public:
    bool bIsEmpty;
    int iPositionX, iPositionY;

    Case()
    {
        this->bIsEmpty = true;
        this->iPositionX = 0;
        this->iPositionY = 0;
    }
};

class Grid
{
public:
    bool bIsFull;
    Case cGrid[16];

    Grid()
    {
        this->bIsFull = false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Grid grid;
    for (int i = 0; i < 16; i++)
    {
        std::cout << grid.cGrid[i].iPositionX;
        if ((i+1) % 4 == 0)
            std::cout << "\n";
    }
}