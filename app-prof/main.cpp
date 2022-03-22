#include <stdio.h>
#include <sys/time.h>
#include <math.h>

double consumeCpu1() {
    double x = 1;
    for(double i=1;i<1000000000;i++) {
        x += sqrt(i);
    }

    return x;
}


struct timeval consumeCpu2() {
    struct timeval date;
    for(int i=1;i<200000000;i++) {
        gettimeofday(&date, NULL);
    }

    return date;
}

void consumeCpu3() {
    int total = 4000000;

    for(int i=1;i<total;i++) {
        printf("%d ", i);
        fflush(stdout);
    }

    // for(int i=1;i<total;i++) printf("%d ", i);
    // for(int i=1;i<total;i++) printf("%d\n", i);
}

int main() {
    consumeCpu2();
    consumeCpu1();
    consumeCpu3();
}