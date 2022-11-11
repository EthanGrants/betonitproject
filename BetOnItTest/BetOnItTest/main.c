/***************************************************************
 *Class:                     CSCI 112                                                                                        *
 *Instructor:               Ronald Burgher                                                                              *
 *Programmer:          Ethan Grant                                                                                    *
 *Project:                  Bet On It Project                                                                             *
 **************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Declare Files
FILE *fp;
FILE *csit;

// Declare Functions
void printReportHeader(void);

void initialStash(double bet, double *stash, double *payoff, double *startingStash);

void addToStash(double bet, double *stash, double *payoff, int *numWon, double *amtWon);

void lossFromStash(double bet, double *stash, double *payoff, int *numLost, double *amtLost);

void printReportFooter(int numWon, double amtWon, int numLost, double amtLost, double startingStash, double payoff, double endingStash);

// Don't Touch
int main()
{
   // set up variables
   char code;
   double bet, payoff, stash, amtWon, amtLost, startingStash, endingStash;
   int numWon, numLost;
    
   // test and open input file and output file.
   if (!(fp = fopen("WagersCopy.txt", "r"))) {
    printf("wagers.txt could not be opened for input.");
    exit(1); }
   if (!(csit = fopen("csit.txt", "w"))) {
    printf("csit.txt could not be opened for output.");
    exit(1); }
    
   //initialize variable values
   bet = payoff = stash = amtWon = amtLost = startingStash = endingStash = 0.0;
   numWon = numLost = 0;
    
   // print out report header
   printReportHeader();
 
   // loop through file
   while (!feof(fp)) {
    fscanf(fp, "%c %lf\n", &code, &bet);
    if (code == 'D') // initial deposit
     initialStash(bet, &stash, &payoff, &startingStash);
    else if (code == 'W') // a win
     addToStash(bet, &stash, &payoff, &numWon, &amtWon);
    else // must have been a loss
     lossFromStash(bet, &stash, &payoff, &numLost, &amtLost); }
 
   // final calculation of profit or loss
   endingStash = stash - payoff;
    
   // print out summary
   printReportFooter(numWon, amtWon, numLost, amtLost, startingStash, payoff,
 endingStash);
    
   // close data and output file
   fclose(csit);
   fclose(fp);
   return 0;
}
// Now can touch
// Do Prototypes
void printReportHeader(void){
    // Print out Header
    printf("%7s","Wager");
    printf("%15s","Won");
    printf("%9s", "Loss");
    printf("%12s", "Stash");
    printf("\n%7s", "-----");
    printf("%16s","-----");
    printf("%9s", "-----");
    printf("%11s","-----");
    
    fprintf(csit,"%7s","Wager");
    fprintf(csit,"%15s","Won");
    fprintf(csit,"%9s", "Loss");
    fprintf(csit,"%12s", "Stash");
    fprintf(csit, "\n%7s", "-----");
    fprintf(csit, "%16s","-----");
    fprintf(csit, "%9s", "-----");
    fprintf(csit, "%11s","-----");
}

void initialStash(double bet, double *stash, double *payoff, double *startingStash){
    // Assign the value of $2,000 to startingstash
    *startingStash = bet;
    *stash = bet;
    
// Declare statements
    printf("\nStarting Stash %28.2f", *startingStash);
    fprintf(csit, "\nStarting Stash %28.2f", *startingStash);
}

void addToStash(double bet, double *stash, double *payoff, int *numWon, double *amtWon){
    // Do calculations
    *payoff += bet * 0.1;
    *amtWon += bet;
    *stash += bet;
    *numWon += 1;
    
    printf("\nWon! %19.2lf %18.2lf ", bet, *stash);
    fprintf(csit,"\nWon! %19.2lf %18.2lf ", bet, *stash);
}

void lossFromStash(double bet, double *stash, double *payoff, int *numLost, double *amtLost){
    // Do calculations
    *payoff += bet * 0.05;
    *amtLost += bet;
    *stash -= bet;
    *numLost += 1;

    printf("\nLost! %18.2lf %18.2lf ", bet, *stash);
    fprintf(csit, "\nLost! %18.2lf %18.2lf ", bet, *stash);
}

void printReportFooter(int numWon, double amtWon, int numLost, double amtLost, double startingStash, double payoff, double endingStash){
    // Print out calculations
    printf("\n\nTotal number Wins: %d\n", numWon);
    printf("Total amount Wins: %.2lf\n", amtWon);
    printf("Total number Losses: %d\n",numLost);
    printf("Total amount Losses: %.2lf\n", amtLost);
    
    printf("\nStarting Stash: %.2lf\n", startingStash);
    printf("Total payoff charge: %.2lf\n", payoff);
    printf("Closing Stash: %.2lf\n", endingStash);
    
    fprintf(csit, "\nTotal number Wins: %d\n", numWon);
    fprintf(csit, "Total amount Wins: %.2lf\n", amtWon);
    fprintf(csit, "Total number Losses: %d\n",numLost);
    fprintf(csit, "Total amount Losses: %.2lf\n", amtLost);
    
    fprintf(csit, "\nStarting Stash: %.2lf\n", startingStash);
    fprintf(csit, "Total payoff charge: %.2lf\n", payoff);
    fprintf(csit, "Closing Stash: %.2lf\n", endingStash);
}

