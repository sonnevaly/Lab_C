#include<stdio.h>

int main(){
    int a = 1;
    int b = 0;
    int new;

    printf("%d\n",a);
    printf("%d\n",b);

    for(int i  = 0; i < 18; i++){
        new = a + b;
        printf("%d\n",new);
        b = a;
        a = new;
    }
    return 0;
}