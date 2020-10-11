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
coord.X = x;#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;

int dinoy;
int dinopos;

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
void getup()
{
    gotoxy(10,2);
    cout<<"Press E to Exit";
    gotoxy(62,2);
    cout<<"SCORE : ";

}
void dino(int jump=0)
{
    static int foot = 0;
    if(jump==0)
    {
        dinoy=0;
    }
    else if(jump == 2)
    {
        dinoy--;
    }
    else
        dinoy++;

    gotoxy(dinopos,14-dinoy); printf("                 ");
    gotoxy(dinopos,15-dinoy); printf("         ÜÛßÛÛÛÛÜ");
	gotoxy(dinopos,16-dinoy); printf("         ÛÛÛÛÛÛÛÛ");
    gotoxy(dinopos,17-dinoy); printf("         ÛÛÛÛÛßßß");
	gotoxy(dinopos,18-dinoy); printf(" Û      ÜÛÛÛÛßßß ");
	gotoxy(dinopos,19-dinoy); printf(" ÛÛÜ  ÜÛÛÛÛÛÛÜÜÜ ");
	gotoxy(dinopos,20-dinoy); printf(" ßÛÛÛÛÛÛÛÛÛÛÛ  ß ");
	gotoxy(dinopos,21-dinoy); printf("   ßÛÛÛÛÛÛÛß     ");
	gotoxy(dinopos,22-dinoy);
	if(jump ==1 || jump == 2)
	{
	printf("    ÛÛß  ßÛ   ");
	gotoxy(2,23-dinoy);
	printf("    ÛÜ   ÛÜ   ");
	}
	else if(foot == 0)
    {
        printf("    ßÛÛß  ßßß    ");
        gotoxy(2,23-dinoy);
        printf("     ÛÜ          ");
        foot=!foot;
    }
    else if (foot == 1)
    {
        printf("      ßÛÛ  ßÛ    ");
        gotoxy(2,23-dinoy);
         printf("          ÛÜ    ");
         foot=!foot;
    }
    gotoxy(2,24-dinoy);
    if (jump==0)
    {
        cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß";
    }
    else
    {
        cout<<"                 ";
    }
    getup();
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
system("cls");
if(op=='1')
    dino();
else if(op=='2')
how_to_play();
else if(op=='3')
    exit(0);
}while(1);
}


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
