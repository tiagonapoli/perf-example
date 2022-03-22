#include <stdio.h>
#include <sys/time.h>
#include <math.h>

double consumeCpu1() {
    double x = 1;
    for(double i=1;i<500000000;i++) {
        x += sqrt(i);
    }

    return x;
}


struct timeval consumeCpu2() {
    struct timeval date;
    for(int i=1;i<100000000;i++) {
        gettimeofday(&date, NULL);
    }

    return date;
}

void consumeCpu3() {
    int total = 2000000;
    for(int i=1;i<total;i++) printf("%d\n", i);
}

int main() {
    consumeCpu2();
    consumeCpu1();
    consumeCpu3();
}


































    // char buffer[65536];
    // setvbuf(stdout, buffer, _IOFBF, 65536);
    // for(int i=1;i<total;i++) printf("%d\n", i);























    // char buffer[8192];
    // setvbuf(stdout, buffer, _IOFBF, 8192);
    // for(int i=1;i<total;i++) {
    //     printf("%d ", i);
    //     if(i % 5 == 0) printf("\n");
    // }
