#include <stdio.h>

int main(){
    int number;
    
    
    printf("Enter the element: ");
    scanf("%d", &number);
    
    int array1[number];
    int array2[number];
    int sum_of_array[number];

        printf("Enter array1\n");
        for(int i = 0; i < number; i++){
            printf("Element%d:",i+1);
            scanf("%d",&array1[i]);
        }
    
        printf("Enter array2\n");
        for(int j = 0; j < number; j++){
            printf("Element%d: ",j+1);
            scanf("%d",&array2[j]);
        }
            
            for(int k = 0; k < number; k++){
                sum_of_array[k] = array1[k] + array2[k];
            }
            printf("\nSum of arrays: {");
                for(int i = 0; i < number; i++){
                    printf("%d", sum_of_array[i]);
                    if(i < number-1){
                        printf(",");
                    }
                }
                printf("}");

    return 0;
}