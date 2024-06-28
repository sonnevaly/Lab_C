#include <stdio.h>

int main(){
    int Number_Name;
    
    printf("How many name?\n");
    scanf("%d",&Number_Name);

    char Name[Number_Name][10];

    for(int i=0; i < Number_Name; i++){
        printf("Name%d: ",i+1);
        scanf("%s",Name[i]);
    }  
            printf("Those %d name are: ",Number_Name);
    
    for (int i=0 ; i < Number_Name ; i++){
        if(i > 0){

            if(i == Number_Name - 1){
                printf(" and %s",Name[i]);
            }else{
                printf(",%s",Name[i]);
            }

        }else{
            printf("%s",Name[i]);
        }
    }
    printf(".\n");

    return 0;
}