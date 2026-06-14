#include <stdio.h>

int main()
{
    int a[100], n, i, j, k, found = 0, duplicate;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Duplicate elements are: ");
    for(i = 0; i < n; i++) {
        duplicate = 0;

        for(k = 0; k < i; k++) {
            if(a[i] == a[k]) {
                duplicate = 1;
                break;
            }
        }

        if(duplicate) {
            continue;
        }

        for(j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                printf("%d ", a[i]);
                found = 1;
                break;
            }
        }
    }

    if(!found) {
        printf("No duplicates found");
    }

    return 0;
}
