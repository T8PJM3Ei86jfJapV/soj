#include <stdio.h>

#define PI 3.14159267

int main () {
    float diameter, revolution, time;
    int no = 0;
    while (scanf("%f%f%f", &diameter, &revolution, &time), revolution) {
        float distance = (diameter * revolution * PI) / (5280 * 12);
        float MPH = distance / (time / 3600);
        printf("Trip #%d: %.2f %.2f\n", ++no, distance, MPH);
    }
    return 0;
}
