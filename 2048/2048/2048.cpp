// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// C:\Users\vmartinan\source\repos\2048-Cpp\2048\2048
// C:\Users\barhancet\source\repos\2048-Cpp\2048\2048\2048.cpp

#include <iostream>

class Tiles
{
public:
    int iValue;

    Tiles()
    {
        this->iValue = 2;
    }

    ~Tiles()
    {
        std::cout << "Tile Destroyed";
    }
};

class Case
{
public:
    bool bIsEmpty;
    int iPositionX, iPositionY;
    Tiles tTile;

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

    void InitiateGrid()
    {
        int iX = 0;
        int iY = 0;
        for (int i = 0; i < 16; i++)
        {
            this->cGrid[i].iPositionX = iX;
            this->cGrid[i].iPositionY = iY;
            iY++;
            if ((i + 1) % 4 == 0)
            {
                iX++;
                iY = 0;
            }
        }
    }

    void PrintGrid()
    {
        for (int j = 0; j < 9; j++)
        {
            if (i%2 == 0)
            {
                if (j%2 != 0)
                    std::cout << "-";
                else
                    std::cout << " ";
            }
            else
            {
                if (j%2 == 0)
                    std::cout << "|";
                else
                    std::cout << "0";
            }
        }
        std::cout << "\n";
    }
    }
};

class Game
{
public:
    int iPoints;
    Grid gGameGrid;

    Game()
    {
        this->iPoints = 0;
        this->gGameGrid.InitiateGrid();
    }

    int UserEntry()
    {
        std::cout << "Direction: ";
        int direction;
        std::cin >> direction;
        return direction;
    }

};


int main()
{
    std::cout << "Hello World!\n";
    Grid grid;
    Game game;
    grid.InitiateGrid();
    grid.PrintGrid();
    int direction = game.UserEntry();
}
