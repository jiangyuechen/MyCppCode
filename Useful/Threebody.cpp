#include <cmath>
#include <conio.h>
#include <ctime>
#include <iostream>
#include <windows.h>
using namespace std;
int toint(float a) { return ((int)(a * 10 + 5)) / 10; }
void Setpos(float x, float y)
{
    COORD pos;
    pos.X = toint(y * 2), pos.Y = toint(x);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Color(int a)
{
    if (a == 4)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    if (a == 1)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    if (a == 2)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    if (a == 3)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    if (a == 4)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
    if (a == 5)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    if (a == 6)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    if (a == 7)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    if (a == 7)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
    if (a == 8)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
    if (a == 9)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    if (a == 10)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    if (a == 11)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
struct node
{
    float x, y, z;
    float vx, vy, vz;
    float r, m;
    bool life;
} Sun[1000001];
void Push(int a, int b)
{
    float Ax = Sun[a].x - Sun[b].x, Ay = Sun[a].y - Sun[b].y, Dis = sqrt(Ax * Ax + Ay * Ay) * 1.0;
    if (Dis <= 1)
        return; //未撞: Dis>=Sun[a].r||Dis>=Sun[b].r||

    float ac = Sun[a].m * Sun[b].m / (Dis * Dis) * 1.0, afx, afy;
    if (abs(Ax) <= 1)
        return; //afy=ac;
    else if (abs(Ay) <= 1)
        return; //afx=ac;
    else
    {
        float d = abs(Ax / Ay * 1.0);
        afy = sqrt(ac / (1 + d * d)) * 1.0, afx = sqrt(ac / (1 + d * d)) * d * 1.0;
    }
    if (Ax > 0)
        afx *= -1;
    if (Ay > 0)
        afy *= -1;
    Sun[a].vx += afx / Sun[a].m * 5.0;
    Sun[a].vy += afy / Sun[a].m * 5.0;
    Sun[b].vx -= afx / Sun[b].m * 5.0;
    Sun[b].vy -= afy / Sun[b].m * 5.0;
}
int b, T, More = 10, Speed = 100;
void Move()
{
    for (int i = 1; i <= b; i++)
    {
        Setpos(Sun[i].x / More * 1.0, Sun[i].y / More * 1.0);
        cout << "  ";
        Sun[i].x += Sun[i].vx * More / 10.0;
        Sun[i].y += Sun[i].vy * More / 10.0;
        if (Sun[i].x >= 40 * More)
            Sun[i].x = 40 * More, Sun[i].vx = 0;
        if (Sun[i].x <= 1)
            Sun[i].x = 1, Sun[i].vx = -0;
        if (Sun[i].y >= 40 * More)
            Sun[i].y = 40 * More, Sun[i].vy = 0;
        if (Sun[i].y <= 1)
            Sun[i].y = 1, Sun[i].vy = 0;
        Setpos(Sun[i].x / More * 1.0, Sun[i].y / More * 1.0);
        Color(i);
        cout << "O";
    }
    for (int i = 1; i <= b; i++)
        for (int j = i + 1; j <= b; j++)
            Push(i, j);
}
int main()
{
    system("mode con cols=82 lines=42");
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    srand((unsigned)time(NULL));

    //  自己改速度与放大倍数（出界会速度清零），白的是三体行星，还有三个太阳。

    b = 4;
    Sun[1].x = 20, Sun[1].y = 20, Sun[1].vx = 5, Sun[1].vy = 10, Sun[1].m = 509;
    Sun[2].x = 10, Sun[2].y = 5, Sun[2].vx = 1, Sun[2].vy = -5, Sun[2].m = 309;
    Sun[3].x = 10, Sun[3].y = 15, Sun[3].vx = 10, Sun[3].vy = -9, Sun[3].m = 142;
    Sun[4].x = 13, Sun[4].y = 30, Sun[4].vx = 1, Sun[4].vy = 1, Sun[4].m = 193; //改这里!
    //Sun[5].x = 12, Sun[5].y = 25, Sun[5].vx = 2, Sun[5].vy = 3, Sun[4].m = 200;
    while (1)
    {
        T++;
        Move();
        Sleep(Speed);
    }
}