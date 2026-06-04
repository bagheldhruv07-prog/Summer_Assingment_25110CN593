#include<stdio.h>
int main() {
  int sum = 0, n, i,d,temp;
  printf("Enter a number: ");
    scanf("%d", &n);
    temp =  n;

    while(n > 0) {
        d = n % 10;
        sum += d*d*d;
        n /= 10;
    }
    if(temp == sum) {
        printf("%d is an Armstrong number.\n", temp);
    } else {
        printf("%d is not an Armstrong number.\n", temp);
    }
    return 0;  
}
 
