#include "Convert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX_LINE_LENGTH 40
#define NUMBER_OF_CANDIDATES 5


char* convert(int line_number) {
    FILE *file = fopen("text-files/test-tekstil.txt", "r");
    char text_string[MAX_LINE_LENGTH];
    char pref[NUMBER_OF_CANDIDATES];
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

struct person convert_america(int line_person) {
    struct person ny_person;
    FILE *file = fopen("text-files/test-tekstil.txt","r");
    if (file == NULL) {
        perror("Could not open file");
    }

    char temp_text_str[MAX_LINE_LENGTH];
    int current_line = 0;

    // fgets læser max "sizeof(text_string) characters fra file stream -
    // - og gemmer dem i string-arrayet "text_string"
    // fgets stopper med at parse text hvis den rammer en newline
    while (fgets(temp_text_str, sizeof(temp_text_str), file) != NULL) {
        if (current_line == line_person) {
            char temp;
            // printf("Line %d: %s", i, text_string);
            // Sscanf det array hvori fgets har parset text dokumentet til
            // herefter bliver dette skrevet ind i de variabler der er specificeret
            if (sscanf(temp_text_str, "%d( %c", &ny_person.stat, &temp) == 2) {
                // typecasting the char to an in
                ny_person.pref = temp - 'A';
                //printf("stat: %d\nPref: %d\n", ny_person.stat, ny_person.pref);
            } else {
                printf("Error: Could not parse the line.\n");
            }
            fclose(file);
            return ny_person;
        }
        current_line++;
    }
    if (current_line < line_person) {
        printf("The file has fewer than %d lines.\n", line_person);
    }
        // If fgets has read to the last line it returns "ny_person.stat" with -1 to signal the end of the txt
        fclose(file);
        ny_person.stat = -1;
        return ny_person;

}

// kode thats is ligegyldigt
int Lav_tal_om_for_soren(int tal) {
    for (int i = 0, j = 65; ; i++, j++) {
        if ((int)tal == j) {
            tal = i;
            return (int)tal;
        }
    }
}