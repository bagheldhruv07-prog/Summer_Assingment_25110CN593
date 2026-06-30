#include <stdio.h>

int main()
{
    int arr[100], n, i, choice;
    int largest, smallest, sum = 0;

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Insert Elements\n");
        printf("2. Display Elements\n");
        printf("3. Find Largest Element\n");
        printf("4. Find Smallest Element\n");
        printf("5. Find Sum of Elements\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);

                printf("Enter %d elements:\n", n);
                for(i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                printf("Array Elements: ");
                for(i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                largest = arr[0];
                for(i = 1; i < n; i++)
                {
                    if(arr[i] > largest)
                        largest = arr[i];
                }
                printf("Largest Element = %d\n", largest);
                break;

            case 4:
                smallest = arr[0];
                for(i = 1; i < n; i++)
                {
                    if(arr[i] < smallest)
                        smallest = arr[i];
                }
                printf("Smallest Element = %d\n", smallest);
                break;

            case 5:
                sum = 0;
                for(i = 0; i < n; i++)
                {
                    sum += arr[i];
                }
                printf("Sum of Elements = %d\n", sum);
                break;

            case 6:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}