#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <fstream>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int dinoy, dinopos = 2, speed = 40, hscore = 0, i = 100;
clock_t t;

void gotoxy(int x, int y);
void getup();
void delay(unsigned int mseconds);

void how_to_play();
bool obj();
void dino(int jump);

void save();
void load();
void high();
void color(int score);

int main()
{
    load();
    while (1)
    {
        system("cls");
        system("Color 0A");

        gotoxy(10, 5);
        printf("   ------------------------------------------------------------------- ");
        gotoxy(10, 6);
        printf("   |                           DINO RUN                                | ");
        gotoxy(10, 7);
        printf("   ------------------------------------------------------------------- ");
        gotoxy(10, 9);
        printf("                     [1]. LET US PLAY                               ");
        gotoxy(10, 10);
        printf("                     [2]. HOW TO PLAY                               ");
        gotoxy(10, 11);
        printf("                     [3]. DISPLAY THE HIGHEST SCORE                 ");
        gotoxy(10, 12);
        printf("                     [4]. BYE                                       ");

        gotoxy(10, 18);
        printf("ENTER YOUR CHOICE : ");

        char op = _getch();

        if (op == '1')
        {
            system("cls");
            system("Color 07");
            t = clock();

            bool k = true;
            while (k)
            {
                getup();
                while (!kbhit())
                {
                    dino(0);
                    k = obj();
                }

                char ch = _getch();

                if (ch == ' ')
                {
                    for (int i = 0; i < 10; i++)
                    {
                        dino(1);
                        k = obj();
                    }
                    for (int i = 0; i < 10; i++)
                    {
                        dino(2);
                        k = obj();
                    }
                }
                else if (ch == 'E' || ch == 'e')
                    exit(0); //exit
            }
        }
        else if (op == '2')
            how_to_play(); //Instructions
        else if (op == '3')
            high();

        else if (op == '4')
            exit(0); //Exit game
    }
}

void how_to_play()
{
    system("cls");
    gotoxy(20, 5);
    printf("MR. DINO IS ON A JOURNEY OF LIFE!");
    gotoxy(20, 6);
    printf("BUT THE OBSTACLES WON'T LET HIM DO IT PEACEFULLY");
    gotoxy(20, 7);
    printf("HELP MR. DINO IN TRAVELING AND PASS THE OBSTACLES");
    gotoxy(20, 10);
    printf("PRESS SPACEBAR TO JUMP AND AVOID THE OBSTACLES");
    gotoxy(20, 14);
    printf("press any key to return...");
    _getch();
}

void dino(int jump)
{
    static int foot = 0;

    if (jump == 0)
        dinoy = 0;
    else if (jump == 2)
        dinoy--;
    else
        dinoy++;

    gotoxy(dinopos, 14 - dinoy);
    printf("                 ");
    gotoxy(dinopos, 15 - dinoy);
    printf("         млпллллм");
    gotoxy(dinopos, 16 - dinoy);
    printf("         лллллллл");
    gotoxy(dinopos, 17 - dinoy);
    printf("         лллллппп");
    gotoxy(dinopos, 18 - dinoy);
    printf(" л      мллллппп ");
    gotoxy(dinopos, 19 - dinoy);
    printf(" ллм  мллллллммм ");
    gotoxy(dinopos, 20 - dinoy);
    printf(" пллллллллллл  п ");
    gotoxy(dinopos, 21 - dinoy);
    printf("   плллллллп     ");

    if (jump == 1 || jump == 2)
    {
        gotoxy(dinopos, 22 - dinoy);
        printf("    ллп  пл   ");
        gotoxy(2, 23 - dinoy);
        printf("    лм   лм   ");
    }
    else if (foot == 0)
    {
        gotoxy(dinopos, 22 - dinoy);
        printf("    пллп  ппп    ");
        gotoxy(2, 23 - dinoy);
        printf("     лм          ");
        foot = 1;
    }
    else if (foot == 1)
    {
        gotoxy(dinopos, 22 - dinoy);
        printf("      плл  пл    ");
        gotoxy(2, 23 - dinoy);
        printf("          лм    ");
        foot = 0;
    }

    if (jump == 0)
    {
        gotoxy(2, 24 - dinoy);
        printf("ппппппппппппппппппппппппппппппп");
    }
    else
    {
        gotoxy(2, 24 - dinoy);
        printf("                 ");
    }

    delay(speed);
}

bool obj()
{
    static int x = 0, score = 0, type = 0, color = 0;

    if (score > i)
    {
        speed = speed - 5;
        if (color == 0)
        {
            system("Color 70");
            color = 1;
        }
        else
        {
            system("Color 07");
            color = 0;
        }
        i = i + 100;
    }

    if (x == 73 && dinoy < 2)
    {
        system("cls");
        system("Color 04");

        gotoxy(35, 15);
        printf("\aGame Over");
        gotoxy(35, 16);
        printf("Score Obtained = %d", score);

        if (score > hscore)
        {
            gotoxy(35, 17);
            printf("You are amazing");
            gotoxy(35, 18);
            printf("High Score Obtained");
            hscore = score;
            save();
        }
        score = x = color = 0;
        i = 100;
        speed = 40;
        gotoxy(35, 20);
        printf("Press any key to continue");
        _getch();
        main();
    }

    int time = clock() - t;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;
    score = time_taken * 10;
    gotoxy(87, 2);
    printf("     ");
    gotoxy(87, 2);
    printf("%d", score);

    if (type == 0)
    {
        gotoxy(90 - x, 19);
        printf("л  л  л ");
        gotoxy(90 - x, 20);
        printf("л  л  л ");
        gotoxy(90 - x, 21);
        printf("ллллллл ");
        gotoxy(90 - x, 22);
        printf("   л    ");
        gotoxy(90 - x, 23);
        printf("   л    ");
    }
    else if (type == 1)
    {
        gotoxy(90 - x, 21);
        printf("ллллллл ");
        gotoxy(90 - x, 22);
        printf("ллллллл ");
        gotoxy(90 - x, 23);
        printf("ллллллл ");
    }
    else if (type == 2)
    {
        gotoxy(90 - x, 20);
        printf("л  л  л ");
        gotoxy(90 - x, 21);
        printf("л  л  л ");
        gotoxy(90 - x, 22);
        printf("ллллллл ");
        gotoxy(90 - x, 23);
        printf("л  л  л ");
    }

    x++;

    if (x == 89)
    {
        x = 0;
        srand(clock());
        type = rand() % 3;
    }

    return true;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void getup()
{
    gotoxy(10, 2);
    printf("Press E to Exit");
    gotoxy(80, 2);
    printf("SCORE : ");
    gotoxy(2, 24);
    printf("пппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппппп");
}

void save()
{
    std::ofstream file("score.txt");
    if (file.is_open())
        file << hscore << "\n";
    file.close();
}

void load()
{
    std::ifstream file("score.txt");
    if (file.is_open())
        file >> hscore;
    file.close();
}

void high()
{
    system("cls");
    system("Color 0E");
    gotoxy(10, 12);
    printf(" THE HIGHEST SCORE IS %d", hscore);
    gotoxy(10, 14);
    printf("Press any key to return.....");
    _getch();
}
