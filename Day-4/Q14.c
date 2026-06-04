#include<stdio.h>
int main() {
 int n,i,fd = 0,ld = 1,next;
 printf("Enter nth term: ");
 scanf("%d",&n);
    printf("Nth term of Fibonacci Series: ");
      if(n == 1) {
        printf("Nth term: %d", fd);
    }
    else if(n == 2) {
        printf("Nth term: %d", ld);
    }
    else {
        for(i = 3; i <= n; i++) {
            next = fd + ld;
            fd = ld;
            ld = next;
        }
        printf("Nth term: %d", ld);
    }

    return 0;
}
