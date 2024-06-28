#include <stdio.h>

void summation(int n)
{
    int sum;
    sum = (n*(n+1)/2);
    printf("Summation form 1 to %d: %d",n,sum);
}

int main(){

    int n;
    printf("Enter n:");
    scanf("%d",&n);

    summation(n);

return 0;
}