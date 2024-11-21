#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Convert.h"

#define MAX_LINE_LENGTH 256
#define NUMBER_OF_CANDICATES 5


char* convert(int line_number) {
    FILE *file = fopen("text-files/test-tekstil.txt", "r");
    char text_string[MAX_LINE_LENGTH];
    char pref[NUMBER_OF_CANDICATES];
    int current_line = 0;

    while (fgets(text_string, sizeof(text_string), file) != NULL) {
        if (current_line == line_number) {
            printf("Line %d: %s", line_number, text_string);
            /*•	%c captures a single character.
            •	%*f skips the floating-point number that follows the character.
            •	%f matches a floating-point number.
            •	* suppresses assignment (does not store the matched value).
            •	The space between format specifiers ensures that whitespace between groups is ignored.*/
            if (sscanf(text_string, "%c%*f %c%*f %c%*f %c%*f %c%*f",&pref[0], &pref[1], &pref[2], &pref[3],&pref[4])==5) {
                printf("%c %c %c %c %c", pref[0],pref[1],pref[2],pref[3],pref[4]);
            } else {
                printf("Error");
            }
            break; // Exit the loop when the desired line is found
        }
        current_line++;
    }

    if (current_line < line_number) {
        printf("The file has fewer than %d lines.\n", line_number);
    }
}