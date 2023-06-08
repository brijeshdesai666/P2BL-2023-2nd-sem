#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a Structure for batsmen
struct batsmen
{
    char name[100];
    int Six, Four, To_run, To_ball;
    float sr[100];
};

// Create a Structure for bowler
struct bowler
{
    char name[100];
    int G_run, over, T_wic;
    float economy[100];
};

// inisilize varibles for the total of all players
int Total_runs, Total_balls, Total_fours, Total_sixs;
int Total_over, Total_grun, Total_wickets;
int Extra_run;

// Create a function for the entering batsmen details
void Batsmen_Details(struct batsmen *p1, int b)
{
    int sixfour, Extra_run;
    for (int i = 0; i < b; i++)
    {
        printf("Enter name of batsmen %d\n", i + 1);
        scanf("%s", p1[i].name);

        printf("Enter the number of four scored by player %d:\n", i + 1);
        scanf("%d", &p1[i].Four);

        printf("Enter the number of six scored by player %d:\n", i + 1);
        scanf("%d", &p1[i].Six);

        sixfour = ((p1[i].Four * 4) + (p1[i].Six * 6));

        printf("Enter the Extra run of player %d:\n", i + 1);
        scanf("%d", &Extra_run);
        p1[i].To_run = sixfour + Extra_run;

        printf("Enter the number of balls played by the player %d:\n", i + 1);
        scanf("%d", &p1[i].To_ball);
    }
}

// Create a function Bowler_Details for the entring bowler details
void Bowler_Details(struct bowler *b1, int a)
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

// Create a functon for the calculate the strike rate of batsmen , economy of bowler and total run, total balls, total four, toatl six ...
void calulate(struct batsmen *p1, struct bowler *b1, int a, int b)
{
    for (int i = 0; i < b; i++)
    {
        p1[i].sr[i] = (p1[i].To_run * 100.00) / p1[i].To_ball; // Calculate Strike Rate of each batsmen
        Total_runs += p1[i].To_run;
        Total_balls += p1[i].To_ball;
        Total_fours += p1[i].Four;
        Total_sixs += p1[i].Six;
    }
    for (int i = 0; i < a; i++)
    {
        b1[i].economy[i] = b1[i].G_run / (float)b1[i].over; // Calculate Economy of each bowler
        Total_over += b1[i].over;
        Total_grun += b1[i].G_run;
        Total_wickets += b1[i].T_wic;
    }
}

// Create the function Condition for the chack all the condition
void Conditaion(int a, int b)
{
    if (Total_runs > Total_grun) // if the total_runs is greater than Total_given run by the bowler so that is not possible
    {
        printf("\nYour's Entered batsmen run is greater than the given run by the bowler\n");
        printf("It's not possible any case\n");
        printf("Please try again\n");
        exit(0);
    }
    else
    {
        Extra_run = (Total_grun - Total_runs); // Calculate the Extra run like -> No Ball, LPW, White Ball ...
    }

    int total_ball = Total_over * 12; // Covert over in to balls
    if (total_ball < Total_balls)     // if the throw ball through all bowler is less than the total balls so it is not possible
    {
        printf("\npalyed ball by the batsmen is greater than throw ball by the bowler\n"); // print Error Message
        printf("\n\tPlease Try Again\n");
        exit(0); // Exit the program
    }

    if (Total_wickets > 11) // if the Total wickets is greater than 11 so it is not possible because total player is 11 in match
    {
        printf("\n%d batsmen is not available in match!!\n", Total_wickets); // print Error Message
        printf("Your Entering data is worong\nPlease try again!\n");
        exit(0); // Exit the program
    }

    if (b < Total_wickets) // if number of batsmen is less than total wicket so it is not possible
    {
        printf("\nTotal batsmen is %d and Total wickets taken by the bowler is %d\n", b, Total_wickets); // print Error Message
        printf("This is not possible\nPlease try again!\n");
        exit(0); // Exit the program
    }

    printf("\n Thank you for Entering details \n");
}

// Create a function for the display batsmen detaisl
void Show_Batesmen_Details(struct batsmen *p1, int b)
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

// Create a function for the display bowler details
void Show_Bowler_Details(struct bowler *b1, int a)
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

// Create a function for the display match summarty
void Match_Summary(struct batsmen *p1, struct bowler *b1, int a, int b)
{
    char total[6] = "TOTAL";

    printf("\n\n");
    Show_Batesmen_Details(p1, b); // Call the show_Batesmen_Details function for the display  batesmen details
    printf("\n %-14s %-14d %-13d %-11d %-11d\n", total, Total_runs, Total_balls, Total_fours, Total_sixs);

    printf("\n\n\n");
    Show_Bowler_Details(b1, a); // Call the Show_Bowler_Details function for the display bowler details
    printf("\n %-14s %-14d %-13d %-11d\n", total, Total_grun, Total_over, Total_wickets);
    printf("\n\t\tEXTRA RUN: %d\n", Extra_run); // print Extra run
    printf("\n");
}

// Create a function for the display match record
void Match_Record(struct batsmen *p1, struct bowler *b1, int a)
{
    char Run_name[20], Four_name[20], Six_name[20], W_name[20];
    int max_run = 0, max_six = 0, max_four = 0, max_W = 0; // inislize all variable from to zero
    for (int i = 0; i < a; i++)
    {
        if (max_run < p1[i].To_run) // calculate maximum run scored by the batsmen
        {
            max_run = p1[i].To_run;
            strcpy(Run_name, p1[i].name);
        }

        if (max_four < p1[i].Four) // calculate maximum four scored by the batsmen
        {
            max_four = p1[i].Four;
            strcpy(Four_name, p1[i].name);
        }

        if (max_six < p1[i].Six) // calculate maximum six scored by the batsmen
        {
            max_six = p1[i].Six;
            strcpy(Six_name, p1[i].name);
        }

        if (max_W < b1[i].T_wic) // calculate maximum wicket taken by the bowler
        {
            max_W = b1[i].T_wic;
            strcpy(W_name, b1[i].name);
        }
    }

    // Display the all highest score
    printf("\n\n");
    printf("\tHighest runs scored by the batsman %s:  %d\n\n", Run_name, max_run);

    printf("\tMaximum fours scored by the batsman %s: %d\n\n", Four_name, max_four);

    printf("\tMaximum sixes scored by the batsman %s: %d\n\n", Six_name, max_six);

    printf("\tMaximum wickets taken by the bowler %s: %d\n\n", W_name, max_W);
    printf("\n\n");
}

// Main function
int main()
{
    int b, a, choice;

    printf("\n   Enter batsmen details\n");

batsmen: // use go to statement
    printf("Enter the how many batsmen\n");
    scanf("%d", &b);
    if (b > 11)
    {
        printf("\n   Please enter valid batsmen(MAXIMUM - 11)\n");
        goto batsmen;
    }
    struct batsmen *p1 = (struct batsmen *)malloc(b * sizeof(struct batsmen)); // Allocate memory for batsmen

    Batsmen_Details(p1, b); // Call the Batesmen_details function

    printf("\n\n   Enter blower dettails\n");

bowler:
    printf("Enter the how many bowler bolwer\n");
    scanf("%d", &a);
    if (a > 11)
    {
        printf("\n   Please enter valid bowler(MAXIMUM - 11)\n");
        goto bowler;
    }
    struct bowler *b1 = (struct bowler *)malloc(a * sizeof(struct bowler)); // Allocate memory for bowler

    Bowler_Details(b1, a); // Call the bowler_details function

    calulate(p1, b1, a, b); // Call the calculate function for the all calculate
    Conditaion(a, b);       // Call the Condition function for the chack all the condition

    do
    {
        // read choice from user
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
            Show_Batesmen_Details(p1, b); // Call the Show_Batesmen_Details function
            break;
        case 2:
            Show_Bowler_Details(b1, a); // Call the Show_Bowler_Details function
            break;
        case 3:
            Match_Summary(p1, b1, a, b); // Call the match_summary function
            break;
        case 4:
            Match_Record(p1, b1, b); // Call match_record function
            break;
        default:
            printf("\n\tinvalid choice\n"); // print the message for invalid choice
            break;
        }
    } while (choice != 0);

    return 0;
}