#include "convert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LINE_LENGTH 40


int convert_borda(int line_person,char* array_pref) {
    FILE *file = fopen("text-files/test-tekstil.txt", "r");
    char temp_text_str[MAX_LINE_LENGTH];
    int current_line = 0;

    while (fgets(temp_text_str, sizeof(temp_text_str), file) != NULL) {
        if (current_line == line_person) {
            //printf("Line %d: %s\n", line_person, temp_text_str);
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
            return 1;
        }
        current_line++;
    }
    if (current_line < line_person) {
        printf("The file has fewer than %d lines.\n", line_person);
        return 0;
    }
    fclose(file);
}

/* convert_america tager imod en linje på tekstfilen der skal læses.
 * Tekst fil bliver læst og indlæser værdier til struck person der returnes */
struct person convert_america(int line_person) {
    struct person ny_person;
    FILE *file = fopen("text-files/test-tekstil.txt","r"); // Åbner tekst fil i 'r' readmode
    if (file == NULL) {
        perror("Could not open file");
    }

    char temp_text_str[MAX_LINE_LENGTH]; // Laver en temp string for at kunne bruge fgets
    int current_line = 0;

    /* fgets læser max "sizeof(text_string) characters fra file stream -
    * - og gemmer dem i string-arrayet "text_string"
    * fgets stopper med at parse text hvis den rammer en newline */
    while (fgets(temp_text_str, sizeof(temp_text_str), file) != NULL) { // læser linje og gemmer i "temp_text_str"
        if (current_line == line_person) {
            char temp; // midlertidig variabel for at kunne typecast til int senere
            if (sscanf(temp_text_str, "%d( %c", &ny_person.stat, &temp) == 2) { // Sscanf læser en string og indlæser værdier i de specificeret variabler
                ny_person.pref = temp - 'A'; // typecasting the char to an in
            } else {
                printf("Error: Could not parse the line.\n");
            }
            fclose(file);
            return ny_person;
        }
        current_line++;
    }
    if (current_line < line_person) { // Hvis der bliver bedt om at kigge på en linje der ikke findes i tekst filen får man denne error besked
        printf("The file has fewer than %d lines.\n", line_person);
    }

        fclose(file);
        ny_person.stat = -1; // Hvis fgets har læst til en newline returneres 'ny_person.stat' med -1 for at signalere slutningen af tekstfilen
        return ny_person;

}