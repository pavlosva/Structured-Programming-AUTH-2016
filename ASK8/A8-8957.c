#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Complex {
    double r,i;

}complex;
complex sum(complex comp1,complex comp2) {
    complex athroisma;
    athroisma.r = comp1.r + comp2.r;
    athroisma.i = comp1.i + comp2.i;
    return athroisma;
}
complex afairesi(complex comp1,complex comp2) {
    complex result;
    result.r = comp1.r - comp2.r;
    result.i = comp1.i - comp2.i;
    return result;
}
time_t t;
int main() {
    int j=0;
    srand((unsigned) time(&t));
    complex numbers[100],sumup[50],subt[50];
    for(j=0;j<100;j++) {
        numbers[j].r = ((double)rand()/(double)5000);
        printf("%lf\n",numbers[j].r);
        numbers[j].i = ((double)rand()/(double)5000);
        printf("%lf\n",numbers[j].i);
        if(j % 2 !=0) {
            printf("%d\n",j);
            sumup[j/2] = sum(numbers[j-1],numbers[j]);
            subt[j/2] = sum(numbers[j-1],numbers[j]);
        }
    }
    for(j=0;j<50;j++) {
        printf("%lf - %lf\n",sumup[j].r,sumup[j].i);
        printf("%lf - %lf\n",subt[j].r,subt[j].i);
    }
    return 0;
}
