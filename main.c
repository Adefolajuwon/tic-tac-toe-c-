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
    if (link == 'y' || link == 'Y')
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
        printf("Player1 %s chose the X or 0:", u1);
        dec = getchar();
        scanf("%c", &dec);
    } while (dec != 'X' && dec != 'x' && dec != '0');
    if (dec == 'X' || dec == 'x')
    {
        *x = 'X';
        *o = '0';
    }
    else
    {
        *x = '0';
        *o = 'X';
    }
    return 1;
}
int main()
{
    char x, o;
    int player = 1;
    int s;
    int choice, score = -1;
    char symbol, re;
    char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char p1[10], p2[10];

    rules();
    printf("\n\nType 1 to start the game:-\nType 2 to view leader board:-\n");
    scanf("%d", &s);

    switch (s)
    {
    case 1:
        do
        {
            printf("\n Enter player 1 name: ");
            scanf("%s", p1);
            printf("Enter name of player2: ");
            scanf("%s", p2);
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

            scanf("%d", &choice);
            symbol = ((player == 1) ? x : o);

            if (choice >= 1 && choice <= 9 && a[choice - 1] == '0' + choice)
                a[choice - 1] = symbol;
            else
            {
                printf("Wrong Selection\n");
                player--;
            }

            score = checkforwin(a);
            player++;
            board(x, o, p1, p2, a);
        } while (score == -1);

        // Handle the result
        if (score == 1)
            printf("%s wins!\n", (player == 1) ? p1 : p2);
        else
            printf("The game is a draw!\n");

        break;
    }

    return 0;
}

// Other functions remain the same...
