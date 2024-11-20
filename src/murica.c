#include <stdio.h>
#include "murica.h"

#define NUMBER_CANDIDATES 5
#define STATES 50

// Array[] = cali(A0.9, B0.7, C0.6, D0.5, E0.4)
typedef struct {
    int stat;
    char pref;
    int electors;
} states;

void murica(person s, person c) {
    for (int i = 0; i < NUMBER_CANDIDATES; i++) {
      printf("%d", c);
    }
    printf("%d", s);

    for (int i = 0; i < STATES; i++) {
        convert_america();
    }
}