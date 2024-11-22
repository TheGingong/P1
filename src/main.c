#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "murica.h"
#include "borda.h"
#include "Convert.h"

int main(void) {
    char pref[5];
    printf("Hsdfsdfsdfellsdfo worsdfsdfld\n");
    //convert_america(2);
    convert_borda(2,pref);
    for (int i = 0; i < 5;i++) {
        printf("%c ",pref[i]);
    }
    return 0;
}
