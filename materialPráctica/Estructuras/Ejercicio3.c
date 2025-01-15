#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char sign;
    unsigned char num_bytes;
    unsigned char * bytes;

} APint;

APint * suma_APint( APint * i1, APint  * i2);

int main() {




    return 0;
}

APint * suma_APint( APint * i1, APint  * i2) {

    APint * suma;

    suma = (APint*) malloc(sizeof(APint));

    suma->bytes = (char*) malloc((num_bytes) * sizeof(char));

    suma->sign = i1->sign;

    for(int i=0; i <= suma->sign; i++) {

        suma->bytes[i] = i1->bytes[i] + i2->bytes[i];
    }


    return suma;
}
