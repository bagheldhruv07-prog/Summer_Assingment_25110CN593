#include<stdio.h>
int main()
{
    int a[100],i,mid,low,high,flag,n,x;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter %d elements in sorted order: ",n);
    for(i=0;i<n;i++)    {
        scanf("%d",&a[i]);  
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    low=0;
    high=n-1;
    flag=0;
    while(low<=high)    {
        mid=(low+high)/2;
        if(a[mid]==x)        {
            flag=1;
            break;  
        }
        else if(a[mid]<x)        {
            low=mid+1;
        }
        else        {
            high=mid-1;
        }
    }
    if(flag==1)    {
        printf("Element found at index %d.",mid);
    }
    else    {
        printf("Element not found in the array.");
    }
    return 0;
}