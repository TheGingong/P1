#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "murica.h"
#include "borda.h"
#include "Convert.h"

int main(void) {
    int winner = america();
    printf("%d", winner);
    return 0;
}
