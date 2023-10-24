// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// C:\Users\vmartinan\source\repos\2048-Cpp\2048\2048 C:\Users\vicma\source\repos\2048-Cpp\2048\2048
// C:\Users\barhancet\source\repos\2048-Cpp\2048\2048\2048.cpp C:\Users\benar\source\repos\2048-Cpp\2048\2048\2048.cpp

#include <iostream>
#include <conio.h>
#include <vector>
#include <cstdlib>

using namespace std;

class Case
{
public:
    int iValue;

    Case()
    {
        this->iValue = 0;
    }


};

class Grid
{
public:
    bool bIsFull;
    Case* cGrid;

    Grid()
    {
        this->bIsFull = false;
    }

    int BiToMono( int x, int y)
    {
        int result= x*4 + y;
        return result;
    }

    int* MonoToBi(int i)
    {
        int* array;
        array[0] = i/4;
        array[1] = i%4;
        return array;
    }

    int rnd(int n)
    {
        int iNumber = rand() % n;
        return iNumber;
    }

    void InitiateGrid()
    {
        cGrid = new Case[16];
    }

    void DeleteGrid()
    {
        for (int i = 0; i < 16; i++) {
            delete this->cGrid;
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
                        std::cout << this->cGrid[iCaseNb].iValue;
                        iCaseNb++;
                    }
                }
            }
            std::cout << "\n";
        }
    }

    /*
    void linearMove(int x, int y, int* coo, int i = 1) {
        //Algo qui va bouger une tuile sur une ligne jusqu'a ce quelle trouve un obstacle, récursivement
        //coo = array de direction ex([1,0],[0,-1])
        int iDirectionX = coo[0];
        int iDirectionY = coo[1];
        if (this->cGrid[this->BiToMono(x + iDirectionX, y + iDirectionY)].iValue != 0)
            return;
        else if (x + iDirectionX < 0 || x + iDirectionX > 3 || y + iDirectionY < 0 || y + iDirectionY > 3)
            return;
        else
            this->cGrid[this->BiToMono(x + iDirectionX, y + iDirectionY)] = this->cGrid[this->BiToMono(x, y)];
            this->cGrid[this->BiToMono(x + iDirectionX, y + iDirectionY)].bIsEmpty = false;

            this->cGrid[this->BiToMono(x, y)].bIsEmpty = true;
            this->cGrid[this->BiToMono(x, y)].tTile = NULL;
            
            linearMove(x + iDirectionX, y + iDirectionY, coo, i++);
    }*/

    vector<int> ListEmptyCases() {
        //Renvoie la liste des indices dont les valeurs sont 0
        vector<int> vAray;

        for (int i = 0; i < 16; i++) {
            if (this->cGrid[i].iValue == 0)
                vAray.push_back(i);
        }

        return vAray;
    }

    void randNumber() {
        vector<int> iTab = this->ListEmptyCases();
        int iSize = iTab.size();
        int iRandomNumber = iTab[this->rnd(iSize)];
        
        this->cGrid[iRandomNumber].iValue = 2;
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

    void GameLoop()
    {
        char sKey;
        int iAsciiValue;
        bool bIsGame = true;
        while (bIsGame) {


            this->gGameGrid.PrintGrid();

            sKey = _getch(); 
            iAsciiValue = sKey;
                if (iAsciiValue == 75)
                    std::cout << "Pressed left \n";

                else if (iAsciiValue == 77)
                    std::cout << "Pressed right \n";

                else if (iAsciiValue == 80)
                    std::cout << "Pressed down \n";

                else if (iAsciiValue == 72)
                    std::cout << "Pressed up \n";
                      
                if (iAsciiValue == 27)
                    bIsGame = false;
        }
        this->gGameGrid.DeleteGrid();
    }

};




int main()
{
    Grid grid;
    Game game;
    game.gGameGrid.randNumber();
    game.GameLoop();
    
}

