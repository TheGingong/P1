#include <stdio.h>
#include "murica.h"
#include <string.h>
#include "Convert.h"

void america() {
    person x;
    states all_states[STATES];
    int candidates_electors[NUMBER_CANDIDATES];


    for (int i = 0; i < STATES; i++) { //Initiere alle pladser i votes array samt electors til 0
        memset(all_states[i].votes, 0, sizeof(all_states[i].votes));
        all_states[i].electors = 0;
    }

    int i = 0;
    do {
        person current_state = convert_america(i);

        if (current_state.stat == -1) {
            break;
        }

        all_states[current_state.stat].votes[current_state.pref]++;
        i++;


    } while(x.stat != -1);

    for (int i = 0; i < STATES; i++) { //Beregner alle vindere for alle stater
        all_states[i].winner = calculate_winner(all_states[i].votes);
    }
}

int calculate_winner(const int *array) { //Returnere kandidaten med flest stemmer fra staten
    //Tager ikke udgangspunkt i en tie. Hvis det sker, vinder kandidaten med laveste index.
    int winner = 0;
    for(int i = 1; i < NUMBER_CANDIDATES; i++) {
        if(array[i] > array[winner]) {
            winner = i;
        }
    }
    return winner;
}

//Lav et array for hvert stat (evt i et struct), med n antal kandidater.

//I loopet checkes hver stemme for stat og kandidat, og tæller kandidaten op i staten.
//While {person.stat != NULL}

//Derefter laves en funktion, som kan udregne vinderen i den enkelte stat.

//Udregn antal valgmænd???

//Det store regnestykke

//    all_states[ALABAMA].votes[0] = 10;
//    for (int i = 0; i<NUMBER_CANDIDATES; i++) {
//        printf("%d\n",all_states[ALABAMA].votes[i]);
//        //printf("%d\n",y.oklahoma[i]);
//    }

