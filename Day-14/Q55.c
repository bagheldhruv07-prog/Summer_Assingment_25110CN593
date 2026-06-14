#include <stdio.h>
#include <limits.h>

int main()
{
    int a[100], n, i, largest = INT_MIN, secondLargest = INT_MIN;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if(n < 2) {
        printf("Second largest element does not exist");
        return 0;
    }

    for(i = 0; i < n; i++) {
        if(a[i] > largest) {
            secondLargest = largest;
            largest = a[i];
        } else if(a[i] > secondLargest && a[i] != largest) {
            secondLargest = a[i];
        }
    }

    if(largest == secondLargest) {
        printf("Second largest element does not exist");
    } else {
        printf("Second largest element is: %d", secondLargest);
    }

    return 0;
}
