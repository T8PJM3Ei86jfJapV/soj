#include <stdio.h>

int main() {
    int couple[200000], circle[200000];

    int n; // n: number of couples
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            int tmp1, tmp2;
            scanf("%d%d", &tmp1, &tmp2);
            couple[tmp1] = tmp2;
            couple[tmp2] = tmp1;
        }

        int order = 0;
        circle[order++] = 1;
        for (int i = 2; i <= 2*n; i++) { // i: No. in circle
            if (couple[i] == circle[order-1]) {
                circle[order--] = NULL;
            } else {
                circle[order++] = i;
            }
        }

        if (order == 0) {
            printf("%s\n", "Yes");
        } else {
            printf("%s\n", "No");
        }
    }
    return 0;
}