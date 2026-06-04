#include <stdio.h>

int main() {
    int n, i, j, Prime;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i = 2; i <= n; i++) {
        Prime = 1;

        for(j = 2; j <= i/2; j++) {
            if(i % j == 0) {
                Prime = 0;
                break;
            }
        }

        if(Prime == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}