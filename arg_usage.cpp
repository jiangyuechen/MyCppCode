#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc - 1; i++)
    {
        if (!strcmp(argv[i], "-name"))
        {
            printf("new person named %s.", argv[i + 1]);
        }
        else if (!strcmp(argv[i], "-sex"))
        {
            if (!strcmp(argv[i + 1], "female"))
            {
                printf("She");
            }
            else if (!strcmp(argv[i + 1], "male"))
            {
                printf("He");
            }
            else
            {
                printf("Sex must be one of female and male.");
                return 1;
            }
        }
        else if (!strcmp(argv[i], "-age"))
        {
            printf(" is %s year(s) old.", argv[i + 1]);
        }
    }
    return 0;
}