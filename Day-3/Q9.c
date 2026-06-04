#include<stdio.h>
int main(){
    int prime = 1, n, i;
    printf("Enter a number: "); 
    scanf("%d", &n);
    if (n <= 1) {
        prime = 0; 
    } else {
        for (i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                prime = 0; 
                break;
            }
        }
    }
    if (prime == 1) {
        printf("The number is prime.");
    } else {
        printf("The number is not prime.");
    }
    return 0;
}