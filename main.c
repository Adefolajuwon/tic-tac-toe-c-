#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef _WIN32
#define OS "nt"
#elif __unix__
#define OS "posix"
#endif
#define TRUE 1
#define FALSE 0
void rules();
int main()
{
    char x, o;
    int s;
    char a[9] = {'1',
                 '2',
                 '3',
                 '4',
                 '5',
                 '6',
                 '7',
                 '8',
                 '9'};
    char p1[10], p2[10];

    rules();
    printf("\n\nType 1 to start the game:-\nType 2 to view leader board:-\n");
    scanf('%d', &s);
    switch (s)
    {

    case 1:
        do
        {
            printf('\n Enter player 1 name: ');
            scanf('%s', p1);
            printf("Enter name of player2: ");
            scanf("%s", p2);
            !strcmp(p1, p2) ? printf("Enter names of different players!\n\n") : FALSE;
        } while (!strcmp(p1, p2));
        decision(&x, &o, &p1);
    }
}
void rules()
{
    char link;
    printf("\tTic-Tac-Toe\n\n");
    printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
    printf("Rules:-\n");
    printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
    printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
    printf("\n\nEnjoy the game! Be a Winner!\n\n");
    printf("For more clarifications press Y else type any other character:- ");
    scanf("%c", &link);
    if (system == 'y' || system == 'Y')
    {
        if (OS == "nt")
            system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
        if (OS == "posix")
            system("firefox http://www.wikihow.com/Play-Tic-Tac-Toe");
    }
}
bool decision(char *x, char *o, unsigned char *u1)
{
    char dec;
    printf("\n\n");
    do
    {
        printf("Player1 %s choose the X or 0:", u1);
        dec = getchar();
        scanf("%c", &dec);
    } while (dec != 'X' && dec != 'x' && dec != 'o');
    if (dec == 'x' || dec == "X")
    {
        *x = 'X';
        *o = 'Y';
    }
    else
    {
        *x = 'Y';
        *o = 'X';
    }
    return 1;
};
