#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct batsmen
{
    char name[100];
    int Six, Four, To_run, To_ball;
    float sr[100];
} p1[15];

struct bowler
{
    char name[100];
    int G_run, over, T_wic;
    float economy[100];
} b1[100];

int Total_runs, Total_balls, Total_fours, Total_sixs;
int Total_over, Total_grun, Total_wickets;
int Extra_run;

void Batsmen_Details(int b)
{
    int sixfour;
    for (int i = 0; i < b; i++)
    {
        printf("Enter name of batsmen %d\n", i + 1);
        scanf("%s", p1[i].name);

        printf("Enter the number of four scored by player %d:\n", i + 1);
        scanf("%d", &p1[i].Four);

        printf("Enter the number of six scored by player %d:\n", i + 1);
        scanf("%d", &p1[i].Six);

        sixfour = ((p1[i].Four * 4) + (p1[i].Six * 6));

        printf("Enter the Total run of player %d:\n", i + 1);
        scanf("%d", &p1[i].To_run);

        if (sixfour > p1[i].To_run)
        {
            printf("six and four is greater than the total run of this player!!!It's Not Possible\n");
            printf("\n\tPlease Try Again\n\nyt");
            exit(0);
        }

        printf("Enter the number of balls played by the player %d:\n", i + 1);
        scanf("%d", &p1[i].To_ball);
    }
}

void Bowler_Details(int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Enter name of bowler %d:\n", i + 1);
        scanf("%s", b1[i].name);

        printf("Enter the runs given by the bowler %d:\n", i + 1);
        scanf("%d", &b1[i].G_run);

        printf("Enter the overs bowled by the bowler %d:\n", i + 1);
        scanf("%d", &b1[i].over);

        printf("Enter the wickets taken by the blower %d:\n", i + 1);
        scanf("%d", &b1[i].T_wic);
    }
}
void calulate(int a, int b)
{
    for (int i = 0; i < b; i++)
    {
        p1[i].sr[i] = (p1[i].To_run * 100.00) / p1[i].To_ball;
        Total_runs += p1[i].To_run;
        Total_balls += p1[i].To_ball;
        Total_fours += p1[i].Four;
        Total_sixs += p1[i].Six;
    }
    for (int i = 0; i < a; i++)
    {
        b1[i].economy[i] = b1[i].G_run / (float)b1[i].over;
        Total_over += b1[i].over;
        Total_grun += b1[i].G_run;
        Total_wickets += b1[i].T_wic;
    }
}

void Conditaion(int a, int b)
{
    if (Total_runs > Total_grun)
    {
        printf("\nYour's Entered batsmen run is greater than the given run by the bowler\n");
        printf("It's not possible any case\n");
        printf("Please try again\n");
        exit(0);
    }
    else
    {
        Extra_run = (Total_grun - Total_runs);
    }

    int total_ball = Total_over * 12;
    if (total_ball < Total_balls)
    {
        printf("\npalyed ball by the batsmen is greater than throw ball by the bowler\n");
        printf("\n\tPlease Try Again\n");
        exit(0);
    }

    if (Total_wickets > 11)
    {
        printf("\n%d batsmen is not available in match!!\n", Total_wickets);
        printf("Your Entering data is worong\nPlease try again!\n");
        exit(0);
    }

    if (b < Total_wickets)
    {
        printf("\nTotal batsmen is %d and Total wickets taken by the bowler is %d\n", b, Total_wickets);
        printf("This is not possible\nPlease try again!\n");
        exit(0);
    }

    printf("\n Thank you for Entering details \n");
}

void Show_Batesmen_Details(int b)
{

    printf("\n\n                          batesmen Detail\n");
    printf("===========================================================================\n");
    printf(" Batsman        runs           balls        fours       sixes         sr   \n");
    printf("===========================================================================\n");
    for (int i = 0; i < b; i++)
    {
        printf(" %-14s %-14d %-13d %-11d %-11d %.2f\n", p1[i].name, p1[i].To_run, p1[i].To_ball, p1[i].Four, p1[i].Six, p1[i].sr[i]);
    }
}

void Show_Bowler_Details(int a)
{
    printf("\n\n                           bowler Detail\n");
    printf("=================================================================\n");
    printf(" Bowler         runs          over         wicket       economy\n");
    printf("=================================================================\n");
    for (int i = 0; i < a; i++)
    {
        printf(" %-14s %-14d %-13d %-11d %.2f\n", b1[i].name, b1[i].G_run, b1[i].over, b1[i].T_wic, b1[i].economy[i]);
    }
}

void Match_Summary(int a, int b)
{
    char total[6] = "TOTAL";

    printf("\n\n");
    Show_Batesmen_Details(b);
    printf("\n %-14s %-14d %-13d %-11d %-11d\n", total, Total_runs, Total_balls, Total_fours, Total_sixs);

    printf("\n\n\n");
    Show_Bowler_Details(a);
    printf("\n %-14s %-14d %-13d %-11d\n", total, Total_over, Total_grun, Total_wickets);
    printf("\n\t\tEXTRA RUN: %d\n", Extra_run);
    printf("\n");
}

void Match_Record(int a)
{
    int max_run = 0, max_six = 0, max_four = 0, max_W = 0;
    for (int i = 0; i < a; i++)
    {
        if (max_run < p1[i].To_run)
        {
            max_run = p1[i].To_run;
        }

        if (max_four < p1[i].Four)
        {
            max_four = p1[i].Four;
        }

        if (max_six < p1[i].Six)
        {
            max_six = p1[i].Six;
        }

        if (max_W < b1[i].T_wic)
        {
            max_W = b1[i].T_wic;
        }
    }
    printf("\n\n");
    printf("\tHighest runs scored by the batsman:  %d\n\n", max_run);

    printf("\tMaximum fours scored by the batsman: %d\n\n", max_four);

    printf("\tMaximum sixes scored by the batsman: %d\n\n", max_six);

    printf("\tMaximum wickets taken by the bowler: %d\n\n", max_W);
    printf("\n\n");
}

int main()
{
    int b, a, choice;

    printf("\n   Enter batsmen details\n");

batsmen:
    printf("Enter the how many batsmen\n");
    scanf("%d", &b);
    if (b > 11)
    {
        printf("\n   Please enter valid batsmen(MAXIMUM - 11)\n");
        goto batsmen;
    }
    Batsmen_Details(b);

    printf("\n\n   Enter blower dettails\n");

bowler:
    printf("Enter the how many bowler bolwer\n");
    scanf("%d", &a);
    if (a > 11)
    {
        printf("\n   Please enter valid bowler(MAXIMUM - 11)\n");
        goto bowler;
    }
    Bowler_Details(a);

    calulate(a, b);
    Conditaion(a, b);

    do
    {
        printf("\n\n\tEnter choice\n");
        printf("Enter '1' for the batsmen details\n");
        printf("Enter '2' for the bowler details\n");
        printf("Enter '3' for the match summary\n");
        printf("Enter '4' for the match record\n");
        printf("Enter '0' for exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            system("cls");
            Show_Batesmen_Details(b);
            break;
        case 2:
            system("cls");
            Show_Bowler_Details(a);
            break;
        case 3:
            system("cls");
            Match_Summary(a, b);
            break;
        case 4:
            system("cls");
            Match_Record(b);
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}
