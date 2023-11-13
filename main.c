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
    int player = 1;
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
        board(x, o, p1, p2, a);
        do
        {
            player = ((player % 2) ? 1 : 2);
            if (player == 1)
                printf("%s Type any digit from 1-9 :- ", p1);
            else
                printf("%s Type any digit from 1-9:- ", p2);
            scanf("%d", &decision);
        }
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
bool decision(char *x, char *o, unsigned char *p1)
{
    char dec;
    printf("\n\n");
    do
    {
        printf("Player1 %s choose the X or o:", p1);
        dec = getchar();
        scanf("%c", &dec);
    } while (dec != 'X' && dec != 'x' && dec != 'o');
    if (dec == 'x' || dec == "X")
    {
        *x = 'X';
        *o = '0';
    }
    else
    {
        *x = 'Y';
        *o = '0';
    }
    return 1;
};
void board(char x, char o, unsigned char *p1, unsigned char *p2, char *a)
{
    int i;
    if (OS == "nt")
        system("cls");
    if (OS == "posix")
        system("clear");
    printf("\tTic-Tac-Toe\n\n");
    printf("\n\n");
    printf("%s:- (%c)\n%s:-  (%c)\n\n\n", p1, x, p2, o);

    printf("  %c |  %c | %c\n", a[0], a[1], a[2]);
    printf("    |    |    \n");
    printf("----|----|----\n");
    printf("    |    |    \n");
    printf("  %c |  %c | %c\n", a[3], a[4], a[5]);
    printf("    |    |    \n");
    printf("----|----|----\n");
    printf("  %c |  %c | %c\n", a[6], a[7], a[8]);
    printf("    |    |    \n");
};