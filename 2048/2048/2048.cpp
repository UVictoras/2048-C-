// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// C:\Users\vmartinan\source\repos\projet\2048\2048 C:\Users\vicma\source\repos\2048-Cpp\2048\2048
// C:\Users\barhancet\source\repos\2048-Cpp\2048\2048\2048.cpp C:\Users\benar\source\repos\2048-Cpp\2048\2048\2048.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

using namespace std;



class Case
{
public:
    int iValue;
    bool isMerged;

    Case()
    {
        this->iValue = 0;
        this->isMerged = false;
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
    {   // Method used to convert monodimensional coordinate to bidimensional coordinate
        int result= x*4 + y;
        return result;
    }

    int* MonoToBi(int i)
    {   // Method used to convert bidimensional coordinate to monodimensional coordinate
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
    {   // Method from the grid class to iniate the grid's elements as Cases
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
    {   // Method from the grid class which prints the grid in the console log
        int iCaseNb = 0;
        for (int i = 0; i < 9; i++)
        {
            if (i % 2 == 0)
            {
                std::cout << "---------------------"; 
            }
            else
            {
                for (int j = 0; j < 9; j++)
                {
                    if (j % 2 == 0)
                        std::cout << "|";
                    else
                    {
                        if (this->cGrid[iCaseNb].iValue < 10 && this->cGrid[iCaseNb].iValue > 0)
                        {
                            std::cout << "  " << this->cGrid[iCaseNb].iValue << " ";
                        }
                        else if (this->cGrid[iCaseNb].iValue < 100 && this->cGrid[iCaseNb].iValue > 10)
                        {
                            std::cout << " " << this->cGrid[iCaseNb].iValue << " ";
                        }
                        else if (this->cGrid[iCaseNb].iValue > 100 && this->cGrid[iCaseNb].iValue < 1000)
                        {
                            std::cout << " " << this->cGrid[iCaseNb].iValue;
                        }
                        else if (this->cGrid[iCaseNb].iValue > 1000)
                        {
                            std::cout << this->cGrid[iCaseNb].iValue;
                        }
                        else if (this->cGrid[iCaseNb].iValue == 0)
                        {
                            std::cout << "    ";
                        }

                        iCaseNb++;
                    }
                }
            }
            std::cout << "\n";
        }
    }
    
    int Move(string sDirection, int iIndex)
    { // Method from the grid class used to move the sent tiles to the furthest case to the said direction using recursion
        if (sDirection == "Left")
        {
            if (this->cGrid[iIndex - 1].iValue == 0 && iIndex % 4 != 0)
            {
                return this->Move("Left", iIndex - 1);
            }
            else
            {
                return iIndex;
            }
        }
        else if (sDirection == "Right")
        {
            if (this->cGrid[iIndex + 1].iValue == 0 && (iIndex - 3) % 4 != 0)
            {
                return this->Move("Right", iIndex + 1);
            }
            else
            {
                return iIndex;
            }
        }
        else if (sDirection == "Up")
        {
            if (this->cGrid[iIndex - 4].iValue == 0 && iIndex >= 4)
            {
                return this->Move("Up", iIndex - 4);
            }
            else
            {
                return iIndex;
            }
        }
        else if (sDirection == "Down")
        {
            if (this->cGrid[iIndex + 4].iValue == 0 && iIndex < 12)
            {
                return this->Move("Down",  iIndex + 4);
            }
            else
            {
                return iIndex;
            }
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
    { // Modifie la valeur de la case choisis aléatoirement parmis celles vides
        vector<int> iTab = this->ListEmptyCases();
        int iSize = iTab.size();
        int iRandomNumber = iTab[this->Rnd(iSize)];
        
        this->cGrid[iRandomNumber].iValue = 2;
    }

    Case& operator[](int index)
    {
        return cGrid[index];
    }

    bool isFull() 
    {   // Method from the grid class to check if the grid is full a values, returns true or false
        for (int i = 0; i < 16; i++) {
            if (this->cGrid[i].iValue == 0) {
                return false;
            }
        }
        return true;
    }

    bool noPossibility()
    {   // Method from the grid class to check if there is still a movement possibility in the actual grid, returns true or false
        for (int l = 0; l < 16; l++)
        {
            if (l > 3 && this->cGrid[l].iValue == this->cGrid[l - 4].iValue)
            {
                return false;
            }
            else if (l < 12 && this->cGrid[l].iValue == this->cGrid[l + 4].iValue)
            {
                return false;
            }
            else if (l % 4 != 0 && this->cGrid[l].iValue == this->cGrid[l - 1].iValue)
            {
                return false;
            }
            else if ((l - 3) % 4 != 0 && this->cGrid[l].iValue == this->cGrid[l + 1].iValue)
            {
                return false;
            }
        }
        return true;
    }

    bool Win()
    {
        for (int p = 0; p < 16; p++)
        {
            if (this->cGrid[p].iValue == 2048)
            {
                return true;
            }
        }
        return false;
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
        int iNewIndex, iTemp, iAsciiValue, iScore = 0;
        char sKey; // Initiating our char variable which will be use to get the pressed key
        bool bIsGame = true, isWin = false;
        this->gGameGrid.cGrid[0].iValue = 2;
        this->gGameGrid.cGrid[1].iValue = 4;
        this->gGameGrid.cGrid[2].iValue = 2;
        this->gGameGrid.cGrid[3].iValue = 2;
        while (bIsGame) 
        {
            for (int h = 0; h < 16; h++)
            {
                this->gGameGrid.cGrid[h].isMerged = false;
            }

            std::cout << "Score :" << iScore << "\n";
            this->gGameGrid.PrintGrid();

            if (this->gGameGrid.isFull() == true && this->gGameGrid.noPossibility() == true)  // Checking if the grid is full of tiles and if there is no movement possible, if so we end the game.
            { 
                break;
            }

            if (this->gGameGrid.Win() == true)
            {
                isWin = true;
                break;
            }

            sKey = _getch(); // Function to get the pressed key
            iAsciiValue = sKey; // Getting the ASCII Value of the key

            if (iAsciiValue == 75) // 75 is the ASCII Value of the left arrow key
            {
                for (int i = 0; i < 16; i++) // We go through our array from the top left corner to the bottom right corner
                {
                    if (i % 4 != 0 && this->gGameGrid.cGrid[i].iValue != 0) // i%4 = 0 means we're on the left column so we can't move to the left & it's useless to move left if the value is 0
                    {
                        iNewIndex = this->gGameGrid.Move("Left", i);
                        iTemp = this->gGameGrid.cGrid[i].iValue;
                        this->gGameGrid.cGrid[i].iValue = 0;
                        this->gGameGrid.cGrid[iNewIndex].iValue = iTemp;
                        
                        if (iNewIndex % 4 != 0 && this->gGameGrid.cGrid[iNewIndex - 1].iValue == this->gGameGrid.cGrid[iNewIndex].iValue && this->gGameGrid.cGrid[iNewIndex - 1].isMerged == false) // We check if the case on the left of the selected one has the same value
                        { // If that's the case, we merge them and increment the score
                            this->gGameGrid.cGrid[iNewIndex - 1].iValue *= 2;
                            iScore += this->gGameGrid.cGrid[iNewIndex].iValue;
                            this->gGameGrid.cGrid[iNewIndex].iValue = 0;
                            this->gGameGrid.cGrid[iNewIndex - 1].isMerged = true;
                        }
                    }
                }
            }

            else if (iAsciiValue == 77) // 77 is the ASCII Value of the right arrow key
            {
                for (int i = 15; i > -1; i--) // We go through our array from the bottom right corner to the top left corner
                {
                    if ((i - 3) % 4 != 0 && this->gGameGrid.cGrid[i].iValue != 0) // We substract 3 to our value to have a usable intenger for the % so we can check if we're on the right column
                    { // If we're not on the right column and the value is not 0 then we can move the case
                        iNewIndex = this->gGameGrid.Move("Right", i);
                        iTemp = this->gGameGrid.cGrid[i].iValue;
                        this->gGameGrid.cGrid[i].iValue = 0;
                        this->gGameGrid.cGrid[iNewIndex].iValue = iTemp;
                        if ((iNewIndex - 3) % 4 != 0 && this->gGameGrid.cGrid[iNewIndex + 1].iValue == this->gGameGrid.cGrid[iNewIndex].iValue && this->gGameGrid.cGrid[iNewIndex + 1].isMerged == false) // We check if the case on the right of the selected one has the same value
                        { // If so, we merge them and increment the score
                            this->gGameGrid.cGrid[iNewIndex + 1].iValue *= 2;
                            iScore += this->gGameGrid.cGrid[iNewIndex].iValue;
                            this->gGameGrid.cGrid[iNewIndex].iValue = 0;
                            this->gGameGrid.cGrid[iNewIndex + 1].isMerged = true;
                        }
                    }
                }
            }

            else if (iAsciiValue == 80) // 80 is the ASCII Value of the down arrow key
            {
                for (int i = 15; i > -1; i--) // We go through our array the same way we do for moving right, bottom right to top left
                {
                    if (i < 12 && this->gGameGrid.cGrid[i].iValue != 0) // If i < 12, this means the value is not the index of a case from the last line, if that's the case and the value is not 0, we can move down the case
                    {
                        iNewIndex = this->gGameGrid.Move("Down", i);
                        iTemp = this->gGameGrid.cGrid[i].iValue;
                        this->gGameGrid.cGrid[i].iValue = 0;
                        this->gGameGrid.cGrid[iNewIndex].iValue = iTemp;
                        if (iNewIndex < 12 && this->gGameGrid.cGrid[iNewIndex + 4].iValue == this->gGameGrid.cGrid[iNewIndex].iValue && this->gGameGrid.cGrid[iNewIndex + 4].isMerged == false) // We check if the case downward the selected one has the same value
                        { // If indeed they're equal, we merge them and increment the score
                            this->gGameGrid.cGrid[iNewIndex + 4].iValue *= 2;
                            iScore += this->gGameGrid.cGrid[iNewIndex].iValue;
                            this->gGameGrid.cGrid[iNewIndex].iValue = 0;
                            this->gGameGrid.cGrid[iNewIndex + 4].isMerged = true;
                        }
                    }
                }
            }


            else if (iAsciiValue == 72) // 72 is the ASCII Value of the up arrow key
            {
                for (int i = 0; i < 16; i++) // We go through our array the same way we did to go left, from top left to bottom right
                {
                    if (i >= 4 && this->gGameGrid.cGrid[i].iValue != 0) // We check if we're not on the 1st line by seeing if the index is at least 4, and if the actual case is also not 0, we can move up
                    {
                        iNewIndex = this->gGameGrid.Move("Up", i);
                        iTemp = this->gGameGrid.cGrid[i].iValue;
                        this->gGameGrid.cGrid[i].iValue = 0;
                        this->gGameGrid.cGrid[iNewIndex].iValue = iTemp;
                        if (iNewIndex >= 4 && this->gGameGrid.cGrid[iNewIndex - 4].iValue == this->gGameGrid.cGrid[iNewIndex].iValue && this->gGameGrid.cGrid[iNewIndex - 4].isMerged == false) // We look if the upward case has the same value
                        { // If therefore, the case on top of ours whom value equals the selected one, we mix them and increment the score
                            this->gGameGrid.cGrid[iNewIndex - 4].iValue *= 2;
                            iScore += this->gGameGrid.cGrid[iNewIndex].iValue;
                            this->gGameGrid.cGrid[iNewIndex].iValue = 0;
                            this->gGameGrid.cGrid[iNewIndex - 4].isMerged = true;
                        }
                    }
                }
            }
                      
            if (iAsciiValue == 27) // 27 is the ASCII Value of the Escape key, if we press it we end the game
                bIsGame = false;

            system("cls"); // Clearing the console logs 
        }
        if (isWin == false)
        {
            cout << "You loose";
        }
        else
        {
            std::cout << "You won !";
        }

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

