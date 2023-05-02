// bug!! -- Convert balls into over 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct batsmen
{
    char names[100];
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

void calulate(int a, int b){
    for (int i = 0; i < b; i++)
    {
        p1[i].sr[i] = (p1[i].To_run * 100.00)/p1[i].To_ball;        
        Total_runs += p1[i].To_run; 
        Total_balls += p1[i].To_ball; 
        Total_fours += p1[i].Four; 
        Total_sixs += p1[i].Six; 
    }
    for (int i = 0; i < a; i++)
    {
        b1[i].economy[i]=b1[i].G_run/(float)b1[i].over;
        Total_over += b1[i].over;
        Total_grun += b1[i].G_run;
        Total_wickets += b1[i].T_wic;
    }    
}

int Extra_run;

void Conditaion(){
if (Total_runs > Total_grun)
{
    printf("Your's Entered batsmen run is greater than the given run by the bowler\n");
    printf("It's not possible any case\n");
    printf("Please try again\n");
    exit(0);
    
}else{
    Extra_run = (Total_grun - Total_runs);
}

printf("\n Thank you for Entering details \n");
}

void betsmen_con()
{
    printf("Enter name of batsmen 1");
    scanf("%s", p1[0].names);
    p1[0].Four = 4;
    p1[0].Six = 3;
    p1[0].To_run = 75;
    p1[0].To_ball = 20;

    printf("Enter name of batsmen 2");
    scanf("%s", p1[1].names);
    p1[1].Four = 9;
    p1[1].Six = 2;
    p1[1].To_run = 89;
    p1[1].To_ball = 27;
}

void bowler_con()
{    
    printf("Enter name of bowler 1");
    scanf("%s", b1[0].name);
    b1[0].G_run = 4;
    b1[0].over = 3;
    b1[0].T_wic = 2;
}

void batsmen_details(int b)
{
    char names[100];
    for (int i = 0; i < b; i++)
    {
        printf("Enter name of batsmen %d\n", i + 1);
        scanf("%s", p1[i].names);
        
        printf("Enter the number of four scored by player %d:\n", i + 1);
        scanf("%d", &p1[i].Four);

        printf("Enter the number of six scored by player %d:\n", i + 1);
        scanf("%d", &p1[i].Six);

        printf("Enter the Total run of player %d:\n", i + 1);
        scanf("%d", &p1[i].To_run);

        printf("Enter the number of balls played by the player %d:\n", i + 1);
        scanf("%d", &p1[i].To_ball);
        
    }
}

void bowler_details(int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Enter the bolwer name\n");
        scanf("%s", b1[i].name);
        

        printf("Enter the runs given by the bowler %d:\n", i + 1);
        scanf("%d", &b1[i].G_run);
        
        printf("Enter the overs bowled by the bowler %d:\n", i + 1);
        scanf("%d", &b1[i].over);

        printf("Enter the wickets taken by the blower %d:\n", i + 1);
        scanf("%d", &b1[i].T_wic);
    }
}

void show_batesmen_details(int b)
{
    
    printf("                          batesmen Detail\n");
    printf("===========================================================================\n");
    printf(" Batsman        runs           balls        fours       sixes         sr   \n");
    printf("===========================================================================\n");  
    for (int i = 0; i < b; i++)
    {
        printf(" %-14s %-14d %-13d %-11d %-11d %.2f\n",p1[i].names, p1[i].To_run, p1[i].To_ball,  p1[i].Four, p1[i].Six, p1[i].sr[i]);
    }
    
}

void show_bowler_details(int a){
    printf("                           bowler Detail\n");
    printf("=================================================================\n");
    printf(" Bowler        overs          runs         wicket       economy\n");
    printf("=================================================================\n");
    for (int i = 0; i < a; i++)
    {
        printf(" %-14s %-14d %-13d %-11d %.2f\n",b1[i].name, b1[i].over, b1[i].G_run,  b1[i].T_wic, b1[i].economy[i]);
    }
}

void Match_summary(int a, int b){
    char total[6] = "TOTAL";

    printf("\n\n");
    show_batesmen_details(b);
    printf("\n %-14s %-14d %-13d %-11d %-11d\n", total, Total_runs, Total_balls, Total_fours, Total_sixs);

    printf("\n\n\n");
    show_bowler_details(a);
    printf("\n %-14s %-14d %-13d %-11d\n",total, Total_over, Total_grun, Total_wickets);
    printf("\n\t\tEXTRA RUN: %d\n",Extra_run);
    printf("\n");
}



int main()
{
    int b, a, choice;

    printf("\n   Enter batsmen details\n");

    batsmen:
    printf("Enter the how many batsmen\n");
    scanf("%d",&b);
    if (b > 11)
    {
        printf("\n   Please enter valid batsmen(MAXIMUM - 11)\n");
        goto batsmen;
    }
    batsmen_details(b);
    // betsmen_con();



    printf("\n\n   Enter blower dettails\n");

    bowler:
    printf("Enter the how many bowler bolwer\n");
    scanf("%d",&a);
    if (a > 11)
    {
        printf("\n   Please enter valid bowler(MAXIMUM - 11)\n");
        goto bowler;
    }
    bowler_details(a);
    // bowler_con();

    calulate(a,b);
    Conditaion();
    

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
            show_batesmen_details(b);
            break;
        case 2:
            show_bowler_details(a);
            break;
        case 3:
            Match_summary(a,b);
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}