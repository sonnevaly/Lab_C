#include <stdio.h>

int counts = 2;

void fibonacci(int a, int b)
{
if(counts <= 19){
    int new = a + b;
    printf("%d\n",new);

    b = a;
    a = new;
    counts += 1;

    fibonacci(a, b);
}
else {
    return;
}
}

int main (){

    fibonacci(1 , 0);

    return 0;
}