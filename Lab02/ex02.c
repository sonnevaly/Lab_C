#include <stdio.h>

int main(){
int rows, columns;
    
    printf("Enter Rows: ");
    scanf("%d", &rows);

    printf("Enter Columns: ");
    scanf("%d", &columns);
    
    int array1[rows][columns];
    int array2[rows][columns];
    
    printf("\nEnter the Matrix1\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("Element[%d][%d]: ",i,j);
            scanf("%d",&array1[i][j]);
        }
    }

    printf("\nEnter the Matrix2\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("Element[%d][%d]: ",i,j);
            scanf("%d",&array2[i][j]);
        }
    }

    int Sum[rows][columns];
    int Sub[rows][columns];

    printf("Sum of Matrix\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            Sum[i][j] = array1[i][j] + array2[i][j];
            printf("[%d]",Sum[i][j]);
        }
        printf("\n");
    }

    printf("Sub of Matrix\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            Sum[i][j] = array1[i][j] - array2[i][j];
            printf("[%d]",Sum[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}