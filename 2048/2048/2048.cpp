// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// C:\Users\vmartinan\source\repos\projet\2048\2048 C:\Users\vicma\source\repos\2048-Cpp\2048\2048
// C:\Users\barhancet\source\repos\2048-Cpp\2048\2048\2048.cpp C:\Users\benar\source\repos\2048-Cpp\2048\2048\2048.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <vector>

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

    int Rnd(int n)
    {
        int iNumber = rand() % n;
        return iNumber;
    }

    void InitiateGrid()
    {
        cGrid = new Case[16];

    }

    /*
    void DeleteGrid()
    {
        for (int i = 0; i < 16; i++) {
            delete this->cGrid[i];
        }
        free(cGrid);

    }*/

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
    
    int MoveLeft(int iIndex)
    {

        if (this->cGrid[iIndex - 1].iValue == 0 && iIndex % 4 != 0)
        {
            return this->MoveLeft(iIndex - 1);
        }
        else 
        {
            return iIndex;
        }
    }

    vector<int> ListEmptyCases() 
    {
        //Renvoie la liste des indices dont les valeurs sont 0
        vector<int> vAray;

        for (int i = 0; i < 16; i++) 
        {
            if (this->cGrid[i].iValue == 0)
                vAray.push_back(i);
        }

        return vAray;
    }

    void RandNumber() 
    {
        vector<int> iTab = this->ListEmptyCases();
        int iSize = iTab.size();
        int iRandomNumber = iTab[this->Rnd(iSize)];
        
        this->cGrid[iRandomNumber].iValue = 2;
    }

    Case& operator[](int index)
    {
        return cGrid[index];
    }

    bool isFull() {
        for (int i = 0; i < 16; i++) {
            if (this->cGrid[i].iValue == 0) {
                return false;
            }
        }
        return true;
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
        int iNewIndex;
        char sKey;
        int iAsciiValue;
        bool bIsGame = true;
        while (bIsGame) {

            this->gGameGrid.RandNumber();

            this->gGameGrid.PrintGrid();

            sKey = _getch(); 
            iAsciiValue = sKey;

            if (iAsciiValue == 75)
            {
                for (int i = 0; i < 16; i++)
                {
                    if (i % 4 != 0 && this->gGameGrid.cGrid[i].iValue != 0)
                    {
                        iNewIndex = this->gGameGrid.MoveLeft(i);
                        this->gGameGrid.cGrid[iNewIndex].iValue = this->gGameGrid.cGrid[i].iValue;
                        this->gGameGrid.cGrid[i].iValue = 0;
                        if (iNewIndex % 4 != 0 && this->gGameGrid.cGrid[iNewIndex - 1].iValue == this->gGameGrid.cGrid[iNewIndex].iValue)
                        {
                            this->gGameGrid.cGrid[iNewIndex - 1].iValue *= 2;
                            this->gGameGrid.cGrid[iNewIndex].iValue = 0;
                        }
                    }
                }
            }

            else if (iAsciiValue == 77)
                std::cout << "Pressed right \n";

            else if (iAsciiValue == 80)
                std::cout << "Pressed down \n";

            else if (iAsciiValue == 72)
                std::cout << "Pressed up \n";
                      
            if (iAsciiValue == 27)
                bIsGame = false;

            system("cls");

            if (this->gGameGrid.isFull() == true) {
                break;
            }

        }
        cout << "You loose";
        //this->gGameGrid.DeleteGrid();
    }

};

int main()
{
    srand(time(NULL));
    Grid grid;
    Game game;
    game.GameLoop();
    //game.gGameGrid.DeleteGrid();
}

