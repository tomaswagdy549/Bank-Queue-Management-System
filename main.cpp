#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "Bank.h"
using namespace std;

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

int main()
{
    int choice = 1;
    int maxChoice = 5;
    int ch;
    Bank ElAhly;
    while (1)
    {
        system("cls");
        gotoxy(30, 5);
        SetColor(14);
        printf("Welcome to our Bank , how can i help you ?");
        SetColor(15);

        for (int i = 1; i <= maxChoice; i++)
        {
            gotoxy(30, 6 + i);
            if (i == choice)
            {
                SetColor(12);
            }
            else
            {
                SetColor(15);
            }
            printf(i == choice ? ">> %d. " : "%d. ", i);
            switch (i)
            {
            case 1:
                cout<<"Add Client";
                break;
            case 2:
                cout<<"Show Current Queue";
                break;
            case 3:
                cout<<"Current process";
                break;
            case 4:
                cout<<"Get the process rate";
                break;
            case 5:
                cout<<"Exit";
                break;
            default:
                break;
            }
        }

        gotoxy(30, 13);
        printf("Use the arrow keys to navigate, and press Enter to select.");

        ch = _getch();
        switch (ch)
        {
        case 72:
            if (choice > 1)
            {
                choice--;
            }
            break;
        case 80:
            if (choice < maxChoice)
            {
                choice++;
            }
            break;
        case 13:
            switch (choice)
            {
            case 1:
                system("cls");
                ElAhly.ReceiveClient();
                system("pause");
                break;
            case 2:
                system("cls");
                ElAhly.ShowTheWaitingQueue();
                system("pause");
                break;
            case 3:
                system("cls");
                ElAhly.ShowTheBankStatus();
                system("pause");
                break;
            case 4:
                system("cls");
                ElAhly.showRates();
                system("pause");
                break;
            case 5:
                exit(0);
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}


