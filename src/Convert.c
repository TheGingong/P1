#include "Convert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX_LINE_LENGTH 40
#define NUMBER_OF_CANDIDATES 5


char* convert_borda(int line_person,char* array_pref) {
    FILE *file = fopen("text-files/test-tekstil.txt", "r");
    char temp_text_str[MAX_LINE_LENGTH];
    int current_line = 0;

    while (fgets(temp_text_str, sizeof(temp_text_str), file) != NULL) {
        if (current_line == line_person) {
            printf("Line %d: %s\n", line_person, temp_text_str);
            /*•	%c captures a single character.
            •	%*f skips the floating-point number that follows the character.
            •	%f matches a floating-point number.
            •	* suppresses assignment (does not store the matched value).
            •	The space between format specifiers ensures that whitespace between groups is ignored.*/
            if (sscanf(temp_text_str, "%*d( %c%*f %c%*f %c%*f %c%*f %c%*f",
                &array_pref[0],&array_pref[1], &array_pref[2], &array_pref[3],&array_pref[4])==5) {
            } else {
                printf("Error");
            }
            fclose(file);
            return array_pref;
        }
        current_line++;
    }
    if (current_line < line_person) {
        printf("The file has fewer than %d lines.\n", line_person);
    }
    fclose(file);
}

struct person convert_america(int line_number) {
    struct person ny_person;
    FILE *file = fopen("text-files/test-tekstil.txt","r");
    if (file == NULL) {
        perror("Could not open file");
    }

    char text_string[MAX_LINE_LENGTH];
    int current_line = 0;

    // fgets læser max "sizeof(text_string) characters fra file stream -
    // - og gemmer dem i string-arrayet "text_string"
    // fgets stopper med at parse text hvis den rammer en newline
    while (fgets(text_string, sizeof(text_string), file) != NULL) {
        if (current_line == line_number) {
            int temp;
            // printf("Line %d: %s", i, text_string);
            // Sscanf det array hvori fgets har parset text dokumentet til
            // herefter bliver dette skrevet ind i de variabler der er specificeret
            if (sscanf(text_string, "%d( %c", &ny_person.stat, &temp) == 2) {
                ny_person.pref = Lav_tal_om_for_soren(temp);
                printf("stat: %d\nPref: %d\n", ny_person.stat, ny_person.pref);
            } else {
                printf("Error: Could not parse the line.\n");
            }
            fclose(file);
            return ny_person;
        }
        current_line++;
    }
    if (current_line < line_number) {
        printf("The file has fewer than %d lines.\n", line_number);
    }

    fclose(file);
}

int Lav_tal_om_for_soren(int tal) {
    for (int i = 0, j = 65; ; i++, j++) {
        if ((int)tal == j) {
            tal = i;
            return (int)tal;
        }
    }
}