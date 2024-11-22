#include "borda.h"
#include <stdio.h>
#define Number_of_kandidates 4
#define NUMBER_OF_VOTERS 2

void borda_count(int number_of_kandidates, int number_of_voters) {
    //initialisere arrays
    char candidate[number_of_kandidates]; //alle mulige kandidater sorteret fra a-z
    int candidate_points[number_of_kandidates]; //gemmer point for hver kandidat
    char voter_preference[number_of_kandidates]; //Information om én vælger præference

    //Indlæser værdier i vælger og resultat
    for (int i = 0; i < number_of_kandidates;i++) {
        candidate[i] = 'A' + i; //indlæser char a-z alt efter antal kandidater
        candidate_points[i] = 0; //tildeler 0 point til hver kandidat
    }

    tildel_point(number_of_voters, voter_preference, number_of_kandidates, candidate_points);

    //printer kandidater samt der point
    for (int i = 0; i < number_of_kandidates; i++) {
        printf("%c : %d\n", candidate[i], candidate_points[i]);
    }
    winner(candidate_points,candidate, number_of_kandidates);
}

//placeholder for dave og gakki func
void convert_test(char* array){
    for (int i = 0; i<Number_of_kandidates; i++){
        array[i] = 'A'+i;
    }
}

void tildel_point (int number_of_voters, char* voter_preference, int number_of_kandidates, int* candidate_points) {
    for (int i = 0;i<number_of_voters;i++){
        convert_test(voter_preference); //gakve func - Tager i mod et array og giver ny vælger pref
        for (int i = 0, j = number_of_kandidates; i<number_of_kandidates;i++, j--){
            int k = voter_preference[i] - 'A'; //udregner index som point skal tildeles
            candidate_points[k] += j; //tildeler j point (j bliver talt ned for hver gennemløb)
        }
    }
}

//Sammenligner antal point og printer den/dem med flest
void winner(int* candidate_points, char* candidate, int number_of_kandidates) {
    int nuværende_winner = 0; //holder styr på den indtil-videre højeste pointscore
    //modtager hidtil højeste pointscore
    for (int i = 0; i < number_of_kandidates;i++) {
        if (nuværende_winner <= candidate_points[i]) {
            nuværende_winner = candidate_points[i];
        }
    }
    //printer alle kandidater med højeste pointscore
    for (int i = 0; i < number_of_kandidates; i++) {
        if (nuværende_winner == candidate_points[i]) {
            printf("The winner candidate is: %c \n", candidate[i]);
        }
    }
}
