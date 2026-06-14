#include <stdio.h>

int main()
{
    int a[100], n, i, element, frequency = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to find frequency: ");
    scanf("%d", &element);

    for(i = 0; i < n; i++) {
        if(a[i] == element) {
            frequency++;
        }
    }

    printf("Frequency of %d is: %d", element, frequency);

    return 0;
}
