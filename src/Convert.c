//
// Created by Mathias Kejser on 20/11/2024.
//
#include "Convert.h"
#include <stdio.h>
#include <stdlib.h>

//test
struct person convert_america(int i) {


    FILE *fil_personer = fopen("text-files/test-tekstil.txt", "r");
    struct person ny_person;
    fscanf(fil_personer, "%[^(]( %c ",&ny_person.stat, &ny_person.pref);
    printf("stat: \nPref:\n", ny_person.stat, ny_person.pref);
    fclose(fil_personer);
    return ny_person;
}



