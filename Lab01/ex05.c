#include <stdio.h>

int main(){
    int scores[10];
    int sum = 0;
    float average;

    printf("Enter 10 scores\n");
        for(int i=0; i < 10; i++){
            printf("Enter Score%d: ",i+1);
            scanf("%d",&scores[i]);
            sum += scores[i];
        }
        average = sum/10.0;
        printf("\nAverage score: %.2f\n", average);

    printf("Scores greater than the average:\n");
        for(int j=0; j < 10; j++){
            if(scores[j] > average){ 
                printf("%d\n",scores[j]);
            }
        }

    return 0;
}