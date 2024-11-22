#include <stdio.h>
#include "murica.h"
#include <string.h>

int america() {
    states all_states[STATES];

    // Kalder funktion som laver stater og tildeler valgmænd
    initialize_states(all_states);

    // Sætter alle værdier i i structen all_states til 0
    for (int i = 0; i < NUMBER_CANDIDATES; i++) {
        memset(all_states[i].votes, 0, sizeof(all_states[i].votes));
        all_states[i].electors = 0;
    }

    int index = 0;
    while(convert_america(index) != -1) {
        person current_state = convert_american(index);
        all_states[current_state.stat].votes[current_state.pref]++;
        index++;
    }

    for (int i = 0; i < STATES; i++) { // Beregner alle vindere for alle stater
        all_states[i].winner = calculate_winner(all_states[i].votes);
    }

    return assign_electors(all_states);
}

int calculate_winner(const int *array) { // Returnere kandidaten med flest stemmer fra staten
    // Tager ikke udgangspunkt i en tie. Hvis det sker, vinder kandidaten med laveste index.
    int winner = 0;
    for(int i = 1; i < NUMBER_CANDIDATES; i++) {
        if(array[i] > array[winner]) {
            winner = i;
        }
    }
    return winner;
}

int assign_electors(states all_states[]) {
    int candidates[NUMBER_CANDIDATES];
    for (int i = 0; i < STATES; i++) {
        candidates[all_states[i].winner] += all_states[i].electors;
    }
    // Kald calculate_winner funktionen
    return calculate_winner(candidates);
}

void initialize_states(states all_states[]) {
        all_states[ALABAMA].electors = 9;
        all_states[ALASKA].electors = 3;
        all_states[ARIZONA].electors = 11;
        all_states[ARKANSAS].electors = 6;
        all_states[CALIFORNIA].electors = 54;
        all_states[COLORADO].electors = 10;
        all_states[CONNECTICUT].electors = 7;
        all_states[DELAWARE].electors = 3;
        all_states[DISTRICT_OF_COLUMBIA].electors = 3;
        all_states[FLORIDA].electors = 30;
        all_states[GEORGIA].electors = 16;
        all_states[HAWAII].electors = 4;
        all_states[IDAHO].electors = 4;
        all_states[ILLINOIS].electors = 19;
        all_states[INDIANA].electors = 11;
        all_states[IOWA].electors = 6;
        all_states[KANSAS].electors = 6;
        all_states[KENTUCKY].electors = 8;
        all_states[LOUISIANA].electors = 8;
        all_states[MAINE].electors = 4;
        all_states[MARYLAND].electors = 10;
        all_states[MASSACHUSETTS].electors = 11;
        all_states[MICHIGAN].electors = 15;
        all_states[MINNESOTA].electors = 10;
        all_states[MISSISSIPPI].electors = 6;
        all_states[MISSOURI].electors = 10;
        all_states[MONTANA].electors = 4;
        all_states[NEBRASKA].electors = 5;
        all_states[NEVADA].electors = 6;
        all_states[NEW_HAMPSHIRE].electors = 4;
        all_states[NEW_JERSEY].electors = 14;
        all_states[NEW_MEXICO].electors = 5;
        all_states[NEW_YORK].electors = 28;
        all_states[NORTH_CAROLINA].electors = 16;
        all_states[NORTH_DAKOTA].electors = 3;
        all_states[OHIO].electors = 17;
        all_states[OKLAHOMA].electors = 7;
        all_states[OREGON].electors = 8;
        all_states[PENNSYLVANIA].electors = 19;
        all_states[RHODE_ISLAND].electors = 4;
        all_states[SOUTH_CAROLINA].electors = 9;
        all_states[SOUTH_DAKOTA].electors = 3;
        all_states[TENNESSEE].electors = 11;
        all_states[TEXAS].electors = 40;
        all_states[UTAH].electors = 6;
        all_states[VERMONT].electors = 3;
        all_states[VIRGINIA].electors = 13;
        all_states[WASHINGTON].electors = 12;
        all_states[WEST_VIRGINIA].electors = 4;
        all_states[WISCONSIN].electors = 10;
        all_states[WYOMING].electors = 3;
}