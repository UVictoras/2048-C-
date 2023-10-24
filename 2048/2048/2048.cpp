// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// C:\Users\vmartinan\source\repos\2048-Cpp\2048\2048 C:\Users\vicma\source\repos\2048-Cpp\2048\2048
// C:\Users\barhancet\source\repos\2048-Cpp\2048\2048\2048.cpp

#include <iostream>

class Tiles
{
public:
    int iValue;

    Tiles()
    {
        this->iValue = 0;
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

    int convertBiToMonoDimensional( int x, int y)
    {
        int result= x*4 + y;
        return result;
    }

    int convertMonoToBiDimensional(int i)
    {
        int array[2];
        array[0] = i/4;
        array[1] = i%4;
        return array;
    }

    int rnd()
    {
        return rand()%15;
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
        int iRandomCase;
        for (int j = 0; j < 2; j++)
        {
            iRandomCase = rnd();
            if (this->cGrid[iRandomCase].tTile.iValue == 0)
                this->cGrid[iRandomCase].tTile.iValue = 2;
            else 
                j--;
        }
    }

    void PrintGrid()
    {
        int iCaseNb = 0;
        for (int i = 0; i < 9; i++)
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
                    {
                        std::cout << this->cGrid[iCaseNb].tTile.iValue;
                        iCaseNb++;
                    }
                }
            }
            std::cout << "\n";
        }
    }

    void MoveTiles()
    {
        for (int i = 0; i < 16; i++) {
            //Faire le déplacement des tuiles
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

    void GameLoop()
    {
        bool bIsGame = true;
        while (bIsGame) {
            char iDirection = this->UserEntry();
            std::cout << iDirection << std::endl;
            //Ci-dessous la condition d'arret de la game loop
            if (iDirection == 'o') {
                bIsGame = false;
            }
        }
    }

};

void linearMove(Case cases, int i) {
    //Algo qui va bouger une tuile sur une ligne jusqu'a ce quelle trouve un obstacle, récursivement

}


int main()
{
    std::cout << "Hello World!\n";
    Grid grid;
    Game game;
    grid.InitiateGrid();
    grid.PrintGrid();
    game.GameLoop();
}

