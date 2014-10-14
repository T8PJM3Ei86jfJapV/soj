#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, basis[100], longnum[400];
        char strnum[400];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &basis[i]);
        }
        scanf("%s", strnum);
        printf("%c", '(');
        for (int i = 0; i < n; i++) {
            int rem = 0;
            for (int j = 0; strnum[j] != '\0'; j++) {
                int tmp = strnum[j] - 48 + rem * 10;
                rem = tmp % basis[i];
            }
            printf("%d", rem);
            if (i != n-1) {
                printf("%c", ',');
            }
        }
        printf("%c\n", ')');
    }
    return 0;
}