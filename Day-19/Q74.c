#include <stdio.h>
int main(){
    int a[10][10],b[10][10],c[10][10],i,j,m,n;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of first matrix: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of second matrix: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("The sum of the two matrices is: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            c[i][j]=a[i][j]+b[i][j];
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    return 0;
   

}