// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

void main()
{
    std::cout << "Hello World!\n";
}

class Case {
public : 
    bool bIsEmpty;
    int iPositionX, iPositionY;

    Case(int iX, int iY) 
    {
        this->bIsEmpty = true;
        this->iPositionX = iX;
        this->iPositionY = iY;
    }
}