/* This program prompts user for input of an integer,
 * and returns a seven-segment display of the integer.
 * @author Ali Al-Musawi
 */
#include <stdio.h>
#include <math.h>

int digitCounter(int num);
void numToArray(int num, int numLength, int numArray[]);
void numTo7Segment(int num, int numArray[]);

int main(void) {
    int looping = 1;
    do {
        int userInput;
        printf("Enter an integer: ");
        scanf(" %d", &userInput);
        int numLength = digitCounter(userInput);
        int numArray[numLength];
        numToArray(userInput, numLength, numArray); // numArray has been filled now.
        numTo7Segment(userInput, numArray); // Seven-Segment format has been printed now.
        int unconfirmed = 1; // a logical flag to confirm if a user wants to abort or not.
        char reply;
        do {
            printf("\n\nWould you like to try another integer? (Y/N): ");
            scanf(" %c", &reply);
            if (reply != 'y' && reply != 'Y' && reply != 'n' && reply != 'N')
                printf("\nYou must enter either 'Y' for yes or 'N' for no.");
            else {
                 if (reply == 'n' || reply == 'N') {
                     looping = 0;
                     printf("\nExiting SS_INTEGER...\n");
                 }
                 unconfirmed = 0;
            }
        }
        while (unconfirmed);

        
    }
    while (looping);
    return 0;
}

/* A helper function
 * This function counts the number of digits in an integer.
 * Recall where n denotes a non-negative integer, and N is the number of digits:
 * N(n) = floor(log(n)) + 1, where log() has base 10.
 * @param num the number whose digit length is sought.
 * @return the length of the parameter num.
 */
int digitCounter(int num) {
    if (num == 0) return 1;
    else if (num < 0) num = -1*num;
    return ((int) (log10((float) num) + 1));
}
    


/* A helper function
 * This function fills an array with the digits of an integer.
 * Recall for an non-negative integer n with N digits:
 * n = floor(n/10^(N-1)) + floor((n mod 10^(N-1))/10^(N-2)) + ... 0
 * @param num the integer whose digits are sought.
 * @param numLength the number of digits in parameter num.
 * @param numArray[] an empty array to fill with digits of parameter num.
 */
void numToArray(int num, int numLength, int numArray[]) {
    if (num < 0) num = -1*num;
    for (int i = numLength - 1; i >= 0; i--) {
        numArray[numLength - 1 - i] = num /((int) floor((pow(10, i))));
        num = num % ( (int) floor((pow(10, i))));
    }
}

/* A helper function
 * This function takes the input and prints it out in seven-segment display.
 * @param num the intger the user inputs.
 * @param numArray an array made of the digits of parameter num.
 */
void numTo7Segment(int num, int numArray[]) {
    const char segments[10][3][3] = {
    {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}}, /* 0 */
    {{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, /* 1 */
    {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}}, /* 2 */
    {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}}, /* 3 */
    {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}}, /* 4 */
    {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}}, /* 5 */
    {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}}, /* 6 */
    {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, /* 7 */
    {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}}, /* 8 */
    {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}  /* 9 */
    };
    int negative = (num < 0);
    if (!negative) {
        for (int i = 0; i < 3; i++) {
            for (int r = 0; r < digitCounter(num); r++) {
                for (int j = 0; j < 3; j++) {
                    printf("%c", segments[numArray[r]][i][j]);
                }
            printf("   "); // This ensures adjacent digits have space between them.
            }
		printf("\n"); // This ensures the upper, middle, and lower part of a digit have their own line.
        }
    }
    else {
		 for (int i = 0; i < 3; i++) {
            if (i == 1) printf("___ ");
            else printf("    ");  // This ensures the entire integer is translated right
            for (int r = 0; r < digitCounter(num); r++) {
                for (int j = 0; j < 3; j++) {
                    printf("%c", segments[numArray[r]][i][j]);
                }
            printf("   "); // same as line (102)
            }
		printf("\n");
        }
    }
}

    
    
        