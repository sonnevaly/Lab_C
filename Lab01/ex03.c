#include <stdio.h>

int main(){
    int array[9]={3, -3, 1, 5, 7, 0, 8, 9, 6};
    int number;
    int status;
    
    printf("Enter a number: ");
    scanf("%d",&number);

    for(int i=0 ;i < 9 ;i++){
        if(array[i]=number){
            status = 1;
            break;
        }
    }
            if(status==1){
                printf("\nThe number %d is exist in array",number);
            }else{
                printf("\nThe number %d is not exist in array",number);
            }
    
    return 0;
}