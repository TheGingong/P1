//
// Created by Mathias Kejser on 20/11/2024.
//
#include "Convert.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 256
#define NUMBER_OF_CANDIDATES 5


struct person convert_america(int i) {
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
        if (current_line == i) {
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
    if (current_line < i) {
        printf("The file has fewer than %d lines.\n", i);
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