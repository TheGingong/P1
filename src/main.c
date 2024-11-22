#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "murica.h"
#include "borda.h"
#include "Convert.h"
#define NUMBER_CANDIDATES 5

int main(void) {
    //america();
    //char pref[5];
    //convert_borda(2,pref);
    //for (int i = 0; i < 5;i++) {
    //    printf("%c ",pref[i]);
    //}
    borda_count(NUMBER_CANDIDATES);
    return 0;
}
