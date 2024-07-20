#include<stdio.h>

int main(){
    int a = 0;
    int b = 1;

    for(int i  = 0; i < 18; i++){
        int new;
        new = a + b;
        printf("%d\n",new);

        b = a;
        a = new;
    }
    return 0;
}