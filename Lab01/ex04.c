#include <stdio.h>

int main(){
    int score;
    float max_score=0;
    float min_score=100;

        printf("How many score?\n");
        scanf("%d",&score);

    float list_score[score];
    
    for(int k=0 ; k < score; k++){
        printf("Score%d: ",k+1);
        scanf("%f", &list_score[k]);
    }

    for(int i=0 ; i < score; i++){
        if(list_score[i] > max_score){
            max_score = list_score[i];
        }
    }
    printf("Max Score is: %.2f",max_score);

    for(int j=0 ; j < score; j++){
        if(list_score[j] < min_score){
            min_score = list_score[j];
        }
    }
    printf("\nMin Score is: %.2f",min_score);
    return 0;
}