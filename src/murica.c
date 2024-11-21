#include <stdio.h>
#include "murica.h"

#include <string.h>


void america() {
    person x;
    states all_states[STATES];
    int candidates[NUMBER_CANDIDATES];


    for (int i = 0; i<NUMBER_CANDIDATES; i++) {
        memset(all_states[i].votes, 0, sizeof(all_states[i].votes));
        all_states[i].electors = 0;
    }


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

