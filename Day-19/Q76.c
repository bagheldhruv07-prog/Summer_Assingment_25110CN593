#include <stdio.h>
int main(){
    int a[10][10],b[10][10],i,j,m,n;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of first matrix: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&b[i][j]);
            b[j][i] = a[i][j];
        }
    }
    printf("The transpose of the matrix is: \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}