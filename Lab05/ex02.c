#include <stdio.h>

void summation(int num1, int num2, int num3)
{
    int sum = num1 + num2 + num3;
    printf("Summation = %d",sum);
}

int main(){
    int num1;
    int num2;
    int num3;

    printf("Enter number1: ");
    scanf("%d",&num1);

    printf("Enter number2: ");
    scanf("%d",&num2);

    printf("Enter number3: ");
    scanf("%d",&num3);

    summation(num1, num2, num3);

return 0;
}