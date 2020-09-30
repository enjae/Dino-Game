#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  }
void how_to_play()
{
   gotoxy(20,5); cout<<"1. Press spacebar for jump \n";
   getch();
}

int main()
{
//setcursor(0,0);
do{
system("cls");
gotoxy(10,5); cout<< " -------------------------------------------------------------------";
gotoxy(10,6);cout<<"|                           DINO RUN                                |";
gotoxy(10,7); cout<< " -------------------------------------------------------------------";
gotoxy(10,9); cout<<"1. LET US PLAY ";
gotoxy(10,10);cout<<"2. HOW TO PLAY ";
gotoxy(10,11);cout<<"3. BYE ";
gotoxy(10,13);cout<<"CHOOSE 1,2 or 3: ";
char op=getche();

system("cls");
//if(op=='1') play(); (function yet to be made)
if(op=='2') how_to_play(); //(function yet to be made)
//else if(op=='3') exit(0); (function yet to be made)
}while(1);
}
