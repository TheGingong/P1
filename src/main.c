#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "murica.h"
#include "borda.h"
#include "Convert.h"
#define NUMBER_CANDIDATES 5

int main(void) {
    printf("%d\n", america(NUMBER_CANDIDATES));
    borda_count(NUMBER_CANDIDATES);
    return 0;
}
